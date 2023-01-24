import sys
from itertools import permutations
# 나중에 DP나 DFS로 풀어보자... 백준 사이트 기준 PyPy3으로 제출해야 통과하는 코드

input = sys.stdin.readline

n = int(input())

potions = list(map(int, input().split()))

each_sales = [[] for i in range(n)]

for i in range(n):
    p = int(input())

    for j in range(p):
        each_sales[i].append(list(map(int, input().split())))


# print(each_sales)


cases = permutations(range(0,n), n)

min_cost = float('inf')

for i in cases:
    tmp_potions = potions[:]
    cost = 0
    for j in i:
        cost += tmp_potions[j]
        for r,s in each_sales[j]:
            tmp_potions[r-1] = max(tmp_potions[r-1] - s, 1)

    min_cost = min(min_cost, cost)

print(min_cost)

   
