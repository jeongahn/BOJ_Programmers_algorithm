#baekjoon 1969 silver3 사탕 게임
# 23년 상반기 Foscar 알고리즘 스터디 3조 1주차 4번

import sys

input = sys.stdin.readline

def count(Board):
    Max_len = 1

    for i in range(N):
        cnt = 1
        for j in range(1, N):
            if Board[i][j] == Board[i][j-1]:
                cnt += 1
            else:
                cnt = 1
        
            Max_len = max(Max_len, cnt)
        
        cnt = 1
        for j in range(1, N):
            if Board[j][i] == Board[j-1][i]:
                cnt += 1
            else:
                cnt = 1
        
            Max_len = max(Max_len, cnt)
    
    return Max_len

N = int(input())

board = [list(input()) for _ in range(N)]

result = 0

for i in range(N):
    for j in range(N):
        
        # 열
        if j + 1 < N:
            #인접한 것과 change
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]

            tmp = count(board)

            result = max(result, tmp)

            #다시 되돌려 놓기
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
            

        # 행
        if i + 1 < N:
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]

            tmp = count(board)

            result = max(result, tmp)

            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
        
print(result)