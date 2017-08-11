-- objective:
    -- replicate some native functions that use recursion
    -- such as:
        -- maximum (in array)
        -- replicate
        -- take
        -- reverse
        -- repeat
        -- zip
        -- elem
    -- and implement quicksort
--
    
maximum' :: (Ord a) => [a] -> a
maximum' []     = error "maximum of empty list"
maximum' [x]    = x
maximum' (x:xs) = max x (maximum' xs)

replicate' :: (Num i, Ord i) => i -> a -> [a]
replicate' n x 
    | n <= 0    = []
    | otherwise = x:replicate' (n-1) x

take' :: (Integral i) => i -> [a] -> [a]
take' n _  
    | n <= 0    = []  
take' _ []      = []
take' n (x:xs)  = x : take' (n-1) xs

reverse' :: [a] -> [a]
reverse' []     = []
reverse' (x:xs)  = (reverse' xs) ++ [x]

repeat' :: a -> [a]
repeat' x = x:repeat' x

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (x,y): zip' xs ys

elem' :: (Eq a) => a -> [a] -> Bool
elem' _ [] = False
elem' a (x:xs) 
    | x == a    = True
    | otherwise = elem' a xs

main = do
    print "hola"