#baekjoon 1969 silver3 사탕 게임
# 23년 상반기 Foscar 알고리즘 스터디 3조 1주차 3번

n, k = map(int, input().split())

eratos = [i for i in range(n+1)]
re_eratos = [i for i in range(n+1)]
cnt = 0
result = 0

for i in range(2, n + 1):
    for j in range(i, n+1, i):
        
        if eratos[j] != -1:
            eratos[j] = -1
            cnt += 1

            if cnt == k:
                print(j)
        
