# // baekjoon 1105 silver1 팔
# // 23년 상반기 Foscar 알고리즘 스터디 5조 2주차 1번
# // 그리디 알고리즘



l, r = input().split()

max_eight = 0

if len(l) != len(r):
    max_eight = 0
else:
    for i in range(len(l)):
        if l[i] == r[i] and l[i] == '8':
                max_eight += 1
        else:
            break

print(max_eight)