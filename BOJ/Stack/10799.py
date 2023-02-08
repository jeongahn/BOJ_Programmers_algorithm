# baekjoon 10799 silver2 쇠막대기
# 23년 상반기 Foscar 알고리즘 스터디 4조 3주차 3번
# 스택

sticks_R = list(input())

# print(sticks_R)

answer = 0

stk = []
# cnt_R = 1

# for i in range(len(sticks_R)):
#     if (sticks_R[i] != 0) and (sticks_R[i] == ')' and sticks_R[i-1] == '('):
#         for j in range(len(stk)):
#             stk[j] += cnt_R
#         continue

#     if sticks_R[i] == '(':
#         if i < len(sticks_R) - 1 and sticks_R[i+1] == ')':
#             continue
#         else:
#             stk.append(1)
#     elif sticks_R[i] == ')':
#         answer += stk.pop(len(stk)-1)

# print(answer)
# 이중 for문으로 시간초과

for i in range(len(sticks_R)):
    if sticks_R[i] == '(':
        stk.append('(')
    else: # sticks_R[i] == ')' 조건
        if sticks_R[i-1] == '(':
            stk.pop()
            answer += len(stk)
        else:
            answer += 1
            stk.pop()

print(answer)
