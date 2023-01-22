#baekjoon 10870 피보나치 수 5 bronze2
# 23년 상반기 Foscar 알고리즘 스터디 1조 1주차 1번


fibo = [0 for i in range(21)]

fibo[1] = 1

for i in range(2, len(fibo)):
    fibo[i] = fibo[i-1] + fibo[i-2]

n = input()
n = int(n)
print(fibo[n])
