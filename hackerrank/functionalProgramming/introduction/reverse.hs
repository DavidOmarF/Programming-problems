rev :: [a] -> [a]
rev []     = []
rev (x:xs)  = (rev xs) ++ [x]

main = do
    let arr = take 10 ['a'..'z']
    print $ rev arr