f :: [Int] -> [Int]
f (_:x:xs) = x : f xs
f _ = []

main :: IO ()
main = do
    let arr = [2, 5, 3, 4, 6, 7, 9, 8]
    print $ f arr