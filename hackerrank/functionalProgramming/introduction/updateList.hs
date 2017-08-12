f :: [Int] -> [Int]
f [] = []
f (x:xs)
    | x < 0     = (0 - x) : f xs
    | otherwise = x : f xs

main = do
    let arr = [4, -3, 2]
    print $ f arr