f :: Int -> [Int] -> [Int]
f n [x] = replicate n x
f n (x:xs) = (replicate n x) ++ f n xs

main :: IO ()
main = do
    let n = 5
    let arr = [1, 2, 5, 6, 3, 1]
    print $ f n arr