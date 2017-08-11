import System.IO  

countNT :: String -> [Int]
countNT xs = map (singleLetterCount xs) "ACGT"

singleLetterCount :: String -> Char -> Int
singleLetterCount xs x = length $ filter (==x) xs

print' :: Show a => [a] -> String
print' [] = ""
print' (x:xs) = show x ++ " " ++ print' xs

main = do  
    dnaString <- readFile "rosalind_dna.txt"
    writeFile  "rosalind_dna_out.txt" $ print' $ countNT dnaString