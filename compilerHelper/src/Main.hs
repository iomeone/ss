module Main where

import           Control.Monad.Identity


import           Data.List
import           Data.Traversable (traverse)


import           System.Directory.Tree (
                                        AnchoredDirTree(..), DirTree(..),
                                        filterDir, readDirectoryWith
                                        )
import           System.Directory
import           System.FilePath
import           System.Environment

import           System.Process                    


-- data DirTree a = Failed { name :: FileName,        
--                           err  :: IOException     }
--                | Dir    { name     :: FileName,
--                           contents :: [DirTree a] } 
--                | File   { name :: FileName,
--                           file :: a               }
--                  deriving Show


getDirTreeList :: [DirTree String] -> String-> [String]
getDirTreeList (x@(Dir name contents) : xs) ext= 
  getDirTreeList contents ext ++ getDirTreeList xs ext

getDirTreeList (x@(File name file) : xs) ext = 
  if takeExtension file == ext && takeFileName file /= "externs.json" && isInfixOf "Test"  file /= True  && isInfixOf "test" file /= True  && isInfixOf "bench" file /= True 
    then file : getDirTreeList xs ext
    else getDirTreeList xs ext
  
getDirTreeList [] ext = []

getDirTreeList ((x@(Failed name e)) : xs)  ext = 
  error  $ name ++ " " ++ (show e )

getDirFileList :: String -> String -> IO [String]
getDirFileList dir ext = do
  _:/tree <- readDirectoryWith return dir
  return $ getDirTreeList [tree] ext

-- listFilesDirFiltered :: DirTree a -> Identity  (DirTree a)
-- listFilesDirFiltered tree = do
--     traverse return $ filterDir myPred tree
--   where myPred (Dir ('.':_) _) = False
--         myPred (File n _) = takeExtension n == ".hs"
--         myPred _ = True

main :: IO ()
main = do
  let 
    pursOutput = "genPurs"
    needCopy = [("Main", "Main.cpp"), 
                ("Main", "Main.h")
                ]
  getExecutablePath 

  -- curDir <- getCurrentDirectory

  curDir <- fmap takeDirectory getExecutablePath

  srcList <-  getDirFileList (curDir </> "src") ".purs"

  pkgList <- getDirFileList (curDir </> ".psc-package") ".purs"

  putStrLn $ show $ concat $ intersperse " " srcList ++ pkgList

  callProcess "purs" $ ["compile", "--codegen", "corefn", "--output", pursOutput] ++ srcList ++ pkgList




  corefnJsonFileList <- getDirFileList  (curDir </> pursOutput) ".json"

  callProcess "pscpp" $ ["--ucns"] ++ corefnJsonFileList



  -- putStrLn $ (takeDirectory curDir) </> "genCpp" </> "Main"
  -- putStrLn $ (takeDirectory curDir) </> "juce" </> "Source"

  putStrLn $ curDir </> "genCpp" </> "Main"
  putStrLn $ curDir </> "juce" </> "Source"

  -- callProcess "cp"  [ curDir </> "genCpp" </> "Main" </> "Main.cpp",  curDir </> "juce" </> "Source" </> "Main"]
  
  mapM (\pathTuple -> copyFile (curDir </> "genCpp" </> fst pathTuple </> snd pathTuple )  (curDir </> "juce" </> "Source" </>  fst pathTuple </> snd pathTuple))
       needCopy

  -- copyFile (curDir </> "genCpp" </> "Main" </> "Main.cpp" )  (curDir </> "juce" </> "Source" </> "Main"</> "Main.cpp")


  -- putStrLn $ show $ corefnJsonFileList

  putStrLn "Press any key to continue..."  >> getLine >> return ()






 

  



  -- [Dir {name = "compilerHelper", contents = [Dir {name = "src", contents = [File {name = "Main.hs", file = "D:\\dev\\pcc\\src\\compilerHelper\\src\\Main.hs"}]},
  --   File {name = "Setup.hs", file = "D:\\dev\\pcc\\src\\compilerHelper\\Setup.hs"}]}]