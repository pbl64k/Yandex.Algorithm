
w s = if (all (== 0) s) then False else ((wm s) > 0)

wm s = length $ filter (not . w) (ns s)

ns s = [[t - (if iix == ix then r else 0) | (iix, t) <- zip [0 ..] s] | ix <- [0 .. (pred $ length s)], r <- [1 .. (s !! ix)]]

