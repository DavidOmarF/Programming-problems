f :: [Int] -> Int
f [] = 0
f (x:xs) 
    | odd x     = x + f xs
    | otherwise = f xs

main = do 
    let arr = [1, 4, 2, 5, 3, 5, 3, 5, 6]
    print $ f arr