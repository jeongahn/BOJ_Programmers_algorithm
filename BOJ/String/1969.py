#baekjoon 1969 silver5 DNA
# 23년 상반기 Foscar 알고리즘 스터디 2조 1주차 4번


N, M = map(int, input().split())

DNA= []
sum_HaDist = 0
result_DNA = ""
for i in range(N):
    DNA.append(input())

for idx in range(M):
    cnt = [0 for i in range(4)]
    for nc in range(N):
        if DNA[nc][idx] == 'A':
            cnt[0] += 1
        elif DNA[nc][idx] == 'C':
            cnt[1] += 1
        elif DNA[nc][idx] == 'G':
            cnt[2] += 1
        else:
            cnt[3] += 1
    max_idx = cnt.index(max(cnt))

    if max_idx == 0:
        result_DNA += 'A'
    elif max_idx == 1:
        result_DNA += 'C'
    elif max_idx == 2:
        result_DNA += 'G'
    else:
        result_DNA += 'T'
    
    sum_HaDist += N - max(cnt)

                
print(result_DNA)
print(sum_HaDist)