'''
3+8*7-9*2

1. (3+8)*(7-9)*2 = -96
2. (3+8)*7-9*2 = 136
4. (3+8)*7-(9*2) = 59
5. 3+(8*7)-(9*2) = 41
6. 3+(8*7)-9*2 = 41
7. 3+8*(7-9)*2 = 
8. 3+8*7-(9*2)
9. 3+8*7-9*2


DFS로 괄호를 묶은것과 괄호를 묶지 않은 것으로 구분지어서 재귀함수


'''
# baekjoon 16637 gold3 괄호 추가하기
# 23년 상반기 Foscar 알고리즘 스터디 5조 1주차 4번

length = int(input())
express = input()
answer = float('-inf')


#괄호를 묶을때 연산해주기 위한 함수
def cal(oper, a, b):
    if oper == '+':
        return a + b
    elif oper == '-':
        return a - b
    elif oper == '*':
        return a * b

def DFS(idx, val):

    global answer

    if idx >= length:
        answer = max(answer, val)
        return
    
    if idx == 0:
        oper = '+'
    else:
        oper = express[idx-1]

    if idx + 2 < length:
        tmp = cal(express[idx + 1], int(express[idx]), int(express[idx+2]))
        DFS(idx+4, cal(oper, val, tmp)) 

    DFS(idx + 2, cal(oper, val, int(express[idx])))


DFS(0,0)
print(answer)
