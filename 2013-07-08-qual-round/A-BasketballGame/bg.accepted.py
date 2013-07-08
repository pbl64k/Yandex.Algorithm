
import sys

n, L = map(int, sys.stdin.readline().split(' '))

t = [0, 0]

for ix in range(n):
    i, d = map(int, sys.stdin.readline().split(' '))
    i -= 1
    t[i] += 1 if d == -1 else (2 if d <= L else 3)

print ':'.join(map(str, t))

