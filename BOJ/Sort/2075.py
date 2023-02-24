# baekjoon 2075 silver2 N번째 큰 수
# 23년 상반기 Foscar 알고리즘 스터디 4조 5주차 4번
# Sort

import sys
import heapq


input = sys.stdin.readline


if __name__ == '__main__':
    n = int(input())

    heap = []

    for _ in range(n):
        numbers = map(int, input().split())
        for number in numbers:
            if len(heap) < n:
                heapq.heappush(heap, number)
            else:
                if heap[0] < number:
                    heapq.heappop(heap)
                    heapq.heappush(heap, number)

print(heap[0])