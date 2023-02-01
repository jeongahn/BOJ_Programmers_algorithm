# // baekjoon 1052 silver1 물병
# // 23년 상반기 Foscar 알고리즘 스터디 5조 2주차 1번
# // 그리디 알고리즘

n, k = map(int, input().split())

count = 0

while(bin(n).count(1) > k):
    n += 1
    count += 1

print(count)