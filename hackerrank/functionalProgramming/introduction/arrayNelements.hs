fn :: Int -> [Int]
fn 0 = []
fn x = x : fn (x-1)

main :: IO ()
main = do
    n <- readLn :: IO Int
    print $ fn n