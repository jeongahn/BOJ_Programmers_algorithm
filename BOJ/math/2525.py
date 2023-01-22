#baekjoon 2525 bronze2 오븐 시계
# 23년 상반기 Foscar 알고리즘 스터디 1조 1주차 2번

A, B = map(int, input().split())
C = input()
C = int(C)

plusM = B + C
plusH, realM = 0, 0

if plusM > 59:
    plusH = plusM // 60
    realM = plusM % 60
else:
    realM = plusM

realH = A + plusH

if realH > 23:
    realH %= 24

print(realH, realM)
