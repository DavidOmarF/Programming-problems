getSides :: [(Int, Int)] -> [Float]
getSides (x:y:ts) = distancePoints x y: getSides (y:ts)
getSides _     = []

distancePoints :: (Int, Int) -> (Int, Int) -> Float
distancePoints (x1, y1) (x2, y2) = 
    sqrt $ fromIntegral $ (x1-x2)^2 + (y1-y2)^2

main = do 
    let points = [(0,0), (0,1), (1, 1), (1, 0)]
    print $ getSides points