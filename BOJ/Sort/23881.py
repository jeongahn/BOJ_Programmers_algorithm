# baekjoon 23881 bronze1 알고리즘수업- 선택정렬1
# 23년 상반기 Foscar 알고리즘 스터디 1조 5주차 1번
# Sort

import sys

n, k = map(int, input().split())
li = list(map(int, input().split()))
count = 0

for i in range(n - 1, 0, -1):
    idx = li.index(max(li[: i + 1]))
    if idx != i:
        li[idx], li[i] = li[i], li[idx]
        count += 1
        if count == k:
            print(*li) #이렇게 하면 리스트 형태로 출력이 아니라 리스트안의 값들만을 출력하는 것이 가능하다.
            exit()
print(-1)
