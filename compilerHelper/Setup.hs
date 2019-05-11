import Distribution.Simple

import          Distribution.Simple                                -- preConf
import          Distribution.PackageDescription    hiding (Flag)   -- emptyHookedBuildInfo

import           Distribution.Simple.Setup                         -- configVerbosity

import           Distribution.Simple.Utils                         -- rawSystemExit

import           Distribution.Simple.BuildPaths                    -- getExeSourceFiles 

import           Distribution.Simple.LocalBuildInfo                -- LocalBuildInfo

import           System.FilePath                                   -- </>

import           System.Directory                                  -- getCurrentDirectory

import           System.Process                                    -- callProcess


-- stack build --dump-logs
copyExtLib :: Args -> CopyFlags -> PackageDescription -> LocalBuildInfo -> IO ()
copyExtLib _ flags pkg_descr lbi = do
    cwd <- getCurrentDirectory 
    let 
        appName = "compilerHelper"
        builddir = buildDir lbi
        appPath  = cwd </> builddir </> appName </> "compilerHelper.exe"

        upDir = takeDirectory cwd
        -- binExe = cwd </> "bin" </> progName


    callProcess "cp"  [appPath, upDir]
    -- createDirectoryIfMissing True "genHs"
    -- createDirectoryIfMissing True "genCpp"
    -- createDirectoryIfMissing True "bin"

    -- putStrLn "--------------------- begin copy  exe"

    -- p <- doesFileExist progPath
    -- a <- doesFileExist appPath
    -- if p 
    -- then callProcess "cp"  [progPath, "./bin"]
    -- else putStrLn $ "---------------------" ++ progPath ++ " not exist"

    -- if a
    -- then callProcess "cp"  [appPath, "./bin"]
    -- else putStrLn $ "---------------------" ++ appPath ++ " not exist"

    -- putStrLn "---------------------gen cpp"
    -- if p 
    -- then callProcess binExe  ["--gen-cpp", "./genCpp"]
    -- else return ()

    -- putStrLn "---------------------gen hs"
    -- callProcess binExe  ["--gen-hs", "./genHs"]
 
    -- demoDir <- doesDirectoryExist "./demo/src"
    -- if demoDir
    --     then callProcess binExe  ["--gen-hs", "./demo/src"]
    --     else return ()

    -- demoDir <- doesDirectoryExist "./demo/bin"
    -- if demoDir
    --     then  callProcess "cp"  ["./bin/libcallback.dll", "./demo/bin"]
    --     else return ()
       
    -- copyFile "./cpp/callback.cpp" "./genCpp/callback.cpp"
    -- copyFile "./cpp/callback.h" "./genCpp/callback.h"
    -- copyFile "./cpp/Makefile" "./genCpp/Makefile"

    -- putStrLn "--------------------- begin make dll"
    -- callProcess "make"  [ "--directory=genCpp"]


main = defaultMainWithHooks simpleUserHooks
    {
         postCopy = copyExtLib
    }
