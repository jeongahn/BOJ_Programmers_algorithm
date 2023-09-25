from sys import stdin

for _ in range(int(stdin.readline())):
    h, l = map(int, stdin.readline().rstrip().split())
    p_c = {}

    for i in range(h):
        f = list(map(int, stdin.readline().rstrip().split()))
        for j in range(len(f)):
            if f[j] != -1:
                p_c[f[j]] = (i+1, j+1)
    floor = sorted(p_c.items())

    hh = [1] * (h+1)
    result = 0

    for i, j in floor:
        result += abs(1 - j[0]) * 20
        result += min(abs(hh[j[0]] - j[1]), abs(l - abs(hh[j[0]] - j[1]))) * 5
        hh[j[0]] = j[1]
    print(result)
