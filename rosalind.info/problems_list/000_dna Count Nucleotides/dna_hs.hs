import System.IO  

countNT :: String -> [Int]
countNT xs = map (singleLetterCount xs) "ACGT"

singleLetterCount :: String -> Char -> Int
singleLetterCount xs x = length $ filter (==x) xs

show' :: Show a => [a] -> String
show' [] = ""
show' (x:xs) = show x ++ " " ++ show' xs

main = do  
    dnaString <- readFile "rosalind_dna.txt"
    writeFile  "rosalind_dna_out.txt" $ show' $ countNT dnaString