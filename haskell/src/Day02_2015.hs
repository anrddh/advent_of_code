module Day02_2015 (run2015day02) where

import Data.Text (Text)
import qualified Data.Text as T
import qualified Data.Text.IO as TIO

import Data.List (sort)

newtype Box = B (Integer, Integer, Integer)

parse_and_apply :: (Box -> Integer) -> Text -> Integer
parse_and_apply f = sum . (f <$>) . parse_box

get_slack :: (Integer, Integer, Integer) -> Integer
get_slack (l,w,h) = case sort [l,w,h] of
                      [x,y,_] -> x * y

box_surface_area :: Box -> Integer
box_surface_area (B (l,w,h)) = (2*l*w) + (2*w*h) + (2*h*l) + get_slack (l,w,h)

ribbon_length :: Box -> Integer
ribbon_length (B (l,w,h)) = l*w*h + (min (min (p l w) (p l h)) (p w h))
  where p x y = 2 * (x + y)

parse_box :: Text -> [Box]
parse_box = (f . (T.unpack <$>) . T.split (=='x') <$>) . T.lines
  where f [l,w,h] = B (read l, read w, read h)
        f _       = B (0,0,0)

part_one :: Text -> Integer
part_one = parse_and_apply box_surface_area

part_two :: Text -> Integer
part_two = parse_and_apply ribbon_length

run2015day02 :: IO ()
run2015day02 = do file <- TIO.readFile "2015day02.txt"
                  putStr "Part 1 Answer: "
                  print $ part_one file
                  putStr "Part 2 Answer: "
                  print $ part_two file
