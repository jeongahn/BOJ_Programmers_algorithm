# // baekjoon 2138 gold5 전구와 스위치
# // 23년 상반기 Foscar 알고리즘 스터디 5조 2주차 3번
# // 그리디 알고리즘
from sys import stdin
import copy

n = int(stdin.readline())

first = list(map(int, stdin.readline().rstrip()))

target = list(map(int, stdin.readline().rstrip()))

copy1 = copy.deepcopy(first)
copy2 = copy.deepcopy(first)




def flip_two(a, b):
    first[a] = 1 - first[a] 
    first[b] = 1 - first[b]

def flip_three(a,b,c):
    first[a] = 1 - first[a] 
    first[b] = 1 - first[b]
    first[c] = 1 - first[c]




for i in range(2):
    first = copy1 if i == 0 else copy2
    
    answer = 0

    for j in range(n):
        if j == 0:
            if i == 0 and first != target:
                answer += 1
                flip_two(j, j + 1)
        elif 1 <= j <= n-2:
            if first[j-1] != target[j-1]:
                answer += 1
                flip_three(j-1, j, j + 1)
        elif j == n - 1:
            if first[j-1] != target[j-1]:
                answer += 1
                flip_two(j-1, j)
    
    if first == target:
        print(answer)
        break

if first != target:
    print(-1)



