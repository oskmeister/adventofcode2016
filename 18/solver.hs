my_input = ".^^^.^.^^^^^..^^^..^..^..^^..^.^.^.^^.^^....^.^...^.^^.^^.^^..^^..^.^..^^^.^^...^...^^....^^.^^^^^^^"

memo :: (Int -> Int -> a) -> [[a]]
memo f = map (\x -> map (f x) [0..]) [0..]

store :: [[Bool]]
store = memo is_safe

is_safe :: Int -> Int -> Bool
is_safe r c =
    if r == 0 then my_input !! c == '.'
    else fast_is_safe (r-1) (c-1) == fast_is_safe (r-1) (c+1)

fast_is_safe :: Int -> Int -> Bool
fast_is_safe r c = 
    if c >= length my_input then True
    else if (min r c) < 0 then True
    else store !! r !! c

count_row r = length $ filter (\x -> x == True) (map (fast_is_safe r) [0..(length my_input - 1)])

main = print $ sum $ map count_row [0..3999]
