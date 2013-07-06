
import math
import sys

fin = open('fraction.in', 'r')
fout = open('fraction.out', 'w')

n = int(fin.readline())

def f(x, n):
    if abs(x) <= 2e-8 and n == 0:
        return []
    if n == 0 or abs(x) <= 2e-8:
        return None
    t = math.ceil(1.0 / x)
    while True:
        l = f(x - 1.0 / t, n - 1)
        if l is None:
            t += 1
            continue
        return [t] + l
            
for i in range(n):
    x = int(fin.readline())
    fout.write(' '.join(map(lambda x: str(int(x)), sorted(f(4.0 / x, 3), reverse = True))) + '\n')

