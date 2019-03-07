module Day01_2015 (run2015day01) where

import Data.Text (Text)
import qualified Data.Text as T
import qualified Data.Text.IO as TIO

part_one :: Integral a => Text -> a
part_one = T.foldl f 0
  where f :: Integral a => a -> Char -> a
        f x '(' = x + 1
        f x ')' = x - 1

thd :: (a,b,c) -> c
thd (x,y,z) = z

part_two :: Integral a => Text -> a
part_two = thd . T.foldl f (False, 0, 1)
  where f :: Integral a => (Bool, a, a) -> Char -> (Bool, a, a)
        f (True, x, y) _    = (True, x, y)
        f (False, x, y) '(' = (False, x + 1, y + 1)
        f (False, 0, y) ')' = (True, -1, y)
        f (False, x, y) ')' = (False, x-1, y + 1)

run2015day01 :: IO ()
run2015day01 = do file <- TIO.readFile "2015day01.txt"
                  putStr "Part 1 Answer: "
                  print $ part_one file
                  putStr "Part 2 Answer: "
                  print $ part_two file
