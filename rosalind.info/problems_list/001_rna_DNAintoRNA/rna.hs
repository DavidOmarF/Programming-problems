-- For problem background, go to:
-- http://rosalind.info/problems/rna/

import System.IO  

dnaToRNA :: String -> String
dnaToRNA xs = map (singleNT) xs

singleNT :: Char -> Char
singleNT 'T' = 'U'
singleNT x = x

main = do  
    dnaString <- readFile "rosalind_rna.txt"
    writeFile  "rosalind_rna_out.txt" $ dnaToRNA dnaString