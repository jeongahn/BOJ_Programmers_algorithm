#baekjoon 1527 silver1 금민수의 개수
# 23년 상반기 Foscar 알고리즘 스터디 4조 1주차 4번


# 문제
'''
은민이는 4와 7을 좋아하고, 나머지 숫자 싫어함
금민수는 어떤 수가 4와 7로만 이루어진 수를 말한다.
A와 B가 주어졌을 때 A보다 크거나 같고, B보다 작거나 같은 자연수 중에 금민수인 것의 개수를 출력하는
프로그램 작성

입력 : 첫째 줄에 A와 B가 주어진다. A는 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수.
B는 A보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수

출력 : 첫째 줄에 A보다 크거나 같고, B보다 작거나 같은 자연수 중에 금민수인 것의 개수를 출력한다.

풀이 전략 : 
1. 입력되는 수가 10억이니까 전체 경우의 수를 반복문으로 접근하는 것 보다는 BFS로 4와 7로 구성된
   금민수를 조합해서 그 수가 A와 B 사이에 있는지 확인
2. A와 B사이에 queue에 추가한 값이 있으면 결과값 + 1
3. A와 B사이에 queue에 추가한 값이 없다면 조건문에 들어가지 못하고 pop으로 인해 결국 while문
   벗어나게 될 것
4. 4와 7로 가능한 조합 4,7,44,77,47,77,444,777....
   -- 4*10 + 4, 4*10 + 7
   -- 처음 4와 7값에 *10 후에 +4, +7 하면 될 듯

입력 값
1 10 -> 2
11 20 -> 0
74 77 -> 2
1000000 5000000 -> 64
'''

import sys
input = sys.stdin.readline


a, b = map(int, input().split())
Qu = [4,7] # 조합을 만들기 위해 4와 7은 먼저 queue에 넣어주고 시작 


def BFS(answer):
    
    while len(Qu) > 1:
        tmp = Qu[0]
        Qu.pop(0)

        if tmp <= b:
            if a <= tmp:
                answer += 1
            Qu.append(tmp*10 + 4) 
            Qu.append(tmp*10 + 7) 

    print(answer)

def solution():
    answer = 0
    BFS(answer)


solution()

# 처음에 시간초과가 났던 코드
# import sys
# input = sys.stdin.readline


# a, b = map(int, input().split())

# def Check_minsoo(s):
    
#     check = True

#     for i in s:
#         if i == '4' or i == '7':
#             continue
#         else:
#             check = False
#             break
    
#     if check == True:
#         return 1
#     else:
#         return 0


# def solution():

#     answer = 0 # 출력 결과 값 

#     for i in range(a, b+1):
#         tmp_s = str(i) # 정수형을 문자열로 변환
#         answer += Check_minsoo(tmp_s)

    
#     print(answer)


# solution()