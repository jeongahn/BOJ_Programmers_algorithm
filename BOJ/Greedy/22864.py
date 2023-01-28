# baekjoon 14487 bronze 2 피로도
# 23년 상반기 Foscar 알고리즘 스터디 1조 2주차 3번
# 그리디 알고리즘


lst = list(map(int, input().split()))

a = lst[0] # 한 시간 일하면 쌓이는 피로도
b = lst[1] # 한 시간 일하면 처리하는 일의 양
c = lst[2] # 한 시간 쉬면 줄어드는 피로도 양
m = lst[3] # 넘기면 안되는 피로도 마지노선

# 하루 최대 쉬고, 일하는 시간 총 24시간

answer = 0 # 하루 최대 처리 가능한 일의 양 - 결과 값
stack = 0 # 누적 피로도

for i in range(24):
    if stack + a > m:
        stack -= c
        if stack < 0:
            stack = 0
    else:
        stack += a
        answer += b

print(answer)