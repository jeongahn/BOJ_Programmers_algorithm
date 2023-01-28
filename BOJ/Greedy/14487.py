# baekjoon 14487 bronze 2 욱제는 효도쟁이야!!
# 23년 상반기 Foscar 알고리즘 스터디 1조 2주차 2번
# 그리디 알고리즘

n = int(input())

town = list(map(int, input().split()))

min_cost = 0

for i in town:
    min_cost += i

min_cost -= max(town)

print(min_cost)