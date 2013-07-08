
import sys

ps = [2, 3, 5]

n = int(sys.stdin.readline())

p1, p2 = 3, 5

while True:
    c = p1 * p2 + 1
    k = int(c ** 0.5)
    if k > n:
        break
    if k ** 2 == c:
        print k
    pc = p2
    while True:
        pc += 1
        f = True
        for p in ps:
            if pc % p == 0:
                f = False
                break
        if f:
            ps.append(pc)
            p1, p2 = p2, pc
            break

