
import sys

n = int(sys.stdin.readline())

print n * (n + 1) / 2, 1 if n == 1 else (1 - (n % 2))

