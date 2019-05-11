module Tests (runTests) where

import Prelude.Compat
import Data.List
import Control.Applicative
import Control.Monad

import System.Process
import System.FilePath
import System.IO
import System.Directory

-------------------------------------------------------------------------------
testsDir :: IO (FilePath, FilePath)
-------------------------------------------------------------------------------
testsDir = do
  baseDir <- getCurrentDirectory
  return (baseDir </> "purescript-tests", baseDir)

-------------------------------------------------------------------------------
runTests :: IO ()
-------------------------------------------------------------------------------
runTests = do

  (outputDir, baseDir) <- testsDir

  outputDirExists <- doesDirectoryExist outputDir
  when outputDirExists $ removeDirectoryRecursive outputDir
  createDirectory outputDir

  let srcDir = outputDir </> "src"
  createDirectory srcDir

  callProcess "git" ["clone", "--branch", "v0.12.3", "--depth", "1", "https://github.com/purescript/purescript.git"]
  let passingDir = baseDir </> "purescript" </> "tests" </> "purs" </> "passing"
  passingTestCases <- sort . filter (".purs" `isSuffixOf`) <$> getDirectoryContents passingDir

  setCurrentDirectory outputDir
  callProcess "pscpp" ["--makefile"]

  fetchPackages
  callProcess "git" ["clone", "--depth", "1", "https://github.com/andyarvanitis/purescript-cpp-ffi.git", "ffi"]

  callProcess "rm" ["-rf", ".psc-package/psc-0.12.3/prelude/v4.1.0"]
  callProcess "git" ["clone", "--depth", "1", "https://github.com/andyarvanitis/purescript-prelude.git", ".psc-package/psc-0.12.3/prelude/v4.1.0"]

  let tests = filter (`notElem` skipped) passingTestCases

  tmp <- getTemporaryDirectory
  createDirectoryIfMissing False (tmp </> logpath)
  outputFile <- openFile (tmp </> logpath </> logfile) WriteMode
  hClose outputFile

  -- Run the tests
  --
  forM_ tests $ \inputFile -> do
    --
    -- Compile/build
    --
    putStrLn $ "Compiling test " ++ inputFile ++ " ..."
    setCurrentDirectory outputDir
    copyFile (passingDir </> inputFile) (srcDir </> inputFile)

    let testCaseDir = passingDir </> (takeWhile (/='.') inputFile)
    testCaseDirExists <- doesDirectoryExist testCaseDir
    when testCaseDirExists $ callProcess "cp" ["-R", testCaseDir, srcDir]

    callProcess "make" ["clean"]
    callProcess "make" ["debug", "-j8"]
    --
    -- Run C++ files
    --
    outputFile <- openFile (tmp </> logpath </> logfile) AppendMode
    hPutStrLn outputFile ("\n" ++ inputFile ++ ":")
    proc <- runProcess ("output" </> "bin" </> "main") [] Nothing Nothing Nothing (Just outputFile) Nothing

    removeFile (srcDir </> inputFile)
    when testCaseDirExists $ callProcess "rm" ["-rf", srcDir </> (takeWhile (/='.') inputFile)]

  -- TODO: support failing test cases
  --
  -- let failing = baseDir </> "examples" </> "failing"
  -- failingTestCases <- sort . filter (".purs" `isSuffixOf`) <$> getDirectoryContents failing
  --

  setCurrentDirectory baseDir
  putStrLn "PureScript tests finished"
  putStrLn $ "Total tests available: " ++ show (length passingTestCases)
  putStrLn $ "Tests run: " ++ show (length tests)
  putStrLn $ "Tests skipped: " ++ show (length skipped)

-------------------------------------------------------------------------------
packages :: [String]
-------------------------------------------------------------------------------
packages =
  [ "arrays"
  , "assert"
  , "console"
  , "control"
  , "effect"
  , "foldable-traversable"
  , "functions"
  , "generics-rep"
  , "invariant"
  , "newtype"
  , "partial"
  , "prelude"
  , "proxy"
  , "refs"
  , "st"
  , "type-equality"
  , "typelevel-prelude"
  ]

-------------------------------------------------------------------------------
fetchPackages :: IO ()
-------------------------------------------------------------------------------
fetchPackages = do
  callProcess "psc-package" ["init"]
  mapM (callProcess "psc-package" . (\p -> ["install", p])) packages
  return ()

-------------------------------------------------------------------------------
skipped :: [String]
-------------------------------------------------------------------------------
skipped =
  [ "2172.purs" -- foreign in Main needed (test manually)
  , "EffFn.purs" -- foreign in Main needed (test manually)
  , "FunWithFunDeps.purs" -- foreign in Main needed (test manually)
  , "NumberLiterals.purs" -- unreliable float string comparison (test manually)
  , "PolyLabels.purs" -- foreign in Main needed (test manually)
  , "RowUnion.purs" -- foreign in Main needed (test manually)
  , "ShadowedModuleName.purs" -- ?
  , "StringEdgeCases.purs" -- javascript char encoding specific
  , "StringEscapes.purs" -- Partially javascript-char-encoding-specific (test manually)
  ]

logpath :: FilePath
logpath = "purescript-output"

logfile :: FilePath
logfile = "purescript-tests.out"
