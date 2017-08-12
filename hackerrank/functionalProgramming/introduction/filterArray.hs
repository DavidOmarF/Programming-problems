f :: Int -> [Int] -> [Int]
f n [] = []
f n (x:xs) 
    | x < n    = x : f n xs
    | otherwise = f n xs

main :: IO ()
main = do
    let n = 5
    let arr = [2, 5, 3, 4, 6, 7, 9, 8]
    print $ f n arr