#baekjoon 1712 bronze2 손익분기점
# 23년 상반기 Foscar 알고리즘 스터디 1조 1주차 3번

A, B, C = map(int, input().split())


answer = 0



if B >= C:
    answer = -1
else:
    answer = A // (C - B) + 1

print(answer)
