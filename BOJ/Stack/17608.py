# // baekjoon 17608 bronze2 막대기
# // 23년 상반기 Foscar 알고리즘 스터디 1조 3주차 3번
# // 스택
import sys
input = sys.stdin.readline

n = int(input())

stk = []

for _ in range(n):
    stk.append(int(input()))

MAX = stk[-1]

answer = 1

for i in range(n-1, -1, -1):
    if stk[i] > MAX:
        answer += 1
        MAX = stk[i]
print(answer)
