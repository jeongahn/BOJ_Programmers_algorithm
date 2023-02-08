# // baekjoon 17608 bronze2 막대기
# // 23년 상반기 Foscar 알고리즘 스터디 1조 3주차 4번
# // 큐
from collections import deque
import sys

input = sys.stdin.readline

n = int(input())

cards = deque()

for i in range(n):
    cards.append(i+1)

waste = []

while(len(cards) > 1):
    waste.append(cards.popleft())
    cards.append(cards.popleft())



for i in range(n-1):
    print(waste[i], end = ' ')
print(cards[0])