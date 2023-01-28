# baekjoon 9237 silver5 이장님 초대
# 23년 상반기 Foscar 알고리즘 스터디 1조 2주차 4번
# 그리디 알고리즘

n = int(input())

plants = list(map(int, input().split()))

plants.sort(reverse = True)


plants[0] = plants[0] + 1 # 첫번째 묘목 심는데 걸리는 하루 + 1
a = 2 # 2일차부터 반복문 시작

for i in range(1, len(plants)):
    plants[i] = plants[i] + i + 1 
    
answer = max(plants) + 1 #다 자란 다음날 초대 가능

print(answer)