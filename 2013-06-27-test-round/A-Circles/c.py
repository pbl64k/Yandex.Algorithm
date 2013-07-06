
import math
import sys

fin = open('circles.in', 'r')
fout = open('circles.out', 'w')

n = int(fin.readline())

rs = {}

for i in range(n):
    x1, y1, x2, y2, x3, y3 = map(int, fin.readline().split(' '))
    r = ((((x2 - x1) ** 2 + (y2 - y1) ** 2) * ((x2 - x3) ** 2 + (y2 - y3) ** 2) * ((x3 - x1) ** 2 + (y3 - y1) ** 2)) ** 0.5) / (2 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2))
    if r not in rs:
        rs[r] = 0
    rs[r] += 1

mx = None

for ix in rs:
    if mx is None or mx < rs[ix]:
        mx = rs[ix]

fout.write(str(mx))

