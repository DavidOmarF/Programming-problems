len :: [a] -> Int
len []      = 0
len (x:xs)  = 1 + len xs

main = do 
    let arr = [1, 3, 5, 2, 3]
    print $ len arr