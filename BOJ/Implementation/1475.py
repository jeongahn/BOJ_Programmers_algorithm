#baekjoon 1969 silver5 방 번호
# 23년 상반기 Foscar 알고리즘 스터디 3조 1주차 2번

p_Num = {}

N = input()

for i in N:
    if i == '9':
        tmp = 6

    else:
        tmp = int(i)

    if tmp in p_Num:
        p_Num[tmp] += 1
    else:
        p_Num[tmp] = 1

if 6 in p_Num:
    p_Num[6] = (p_Num[6] // 2) + (p_Num[6] % 2)
result = max(p_Num.values())

print(result)

    