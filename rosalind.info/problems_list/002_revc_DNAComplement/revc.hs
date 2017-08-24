-- For problem background, go to:
-- http://rosalind.info/problems/rna/

import System.IO

reverseComplement :: String -> String
reverseComplement xs = reverse $ map (singleNT) xs

singleNT :: Char -> Char
singleNT x
    | x == 'A' = 'T'
    | x == 'C' = 'G'
    | x == 'G' = 'C'
    | x == 'T' = 'A'
    | otherwise = error "Wrong Nucleotide"

main = do  
    dnaString <- readFile "rosalind_revc.txt"
    writeFile  "rosalind_revc_out.txt" $ reverseComplement dnaString