# baekjoon 14720 bronze 3 우유축제
# 23년 상반기 Foscar 알고리즘 스터디 1조 2주차 1번
# 그리디 알고리즘


import sys

input = sys.stdin.readline

answer = 0 # 총 마신 우유 개수

n = int(input())
store = list(map(int, input().split()))

straw_check = False
milk = 0

for i in range(n):
    if store[i] == milk:
        answer += 1
        milk = (milk + 1) % 3

print(answer)