# baekjoon 19941 silver3 햄버거 분ㅐ
# 23년 상반기 Foscar 알고리즘 스터디 3조 2주차 3번
# 그리디 알고리즘

n, k = map(int, input().split())

table = list(input())
answer = 0

for i in range(n):
    if table[i] == 'P':
        for i in range(max(i-k, 0), min(i+k+1, n)):
            if table[i] == 'H':
                table[i] = 0
                answer += 1
                break
print(answer)

