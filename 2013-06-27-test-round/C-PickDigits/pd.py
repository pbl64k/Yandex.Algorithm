
import math
import sys

fin = open('number.in', 'r')
fout = open('number.out', 'w')

m = {}

def pick_min(s, n):
    if (s, n) not in m:
        if n == 0:
            res = 0
        elif len(s) < n:
            res = 100500
        elif len(s) == n:
            res = int(s)
        else:
            res = min(pick_min(s[1:], n), int(s[0]) * 10 ** (n - 1) + pick_min(s[1:], n - 1))
        m[(s, n)] = res
    return m[(s, n)]

s = str(int(fin.readline()))

fout.write(str(pick_min(s, 4)))

