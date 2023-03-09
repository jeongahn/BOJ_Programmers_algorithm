# import sys

# input = sys.stdin.readline

# def count_Pn(s, m, n):
#     cnt,answer,i = 0,0,0
    
#     while i < (m - 1):
#         if s[i:i+3] == 'IOI':
#             i += 2
#             cnt += 1
#             if cnt == n:
#                 answer += 1
#                 cnt -= 1
#         else:
#             i += 1
#             cnt = 0


#     return answer

# if __name__ == "__main__":

#     n = int(input())
#     m = int(input())

#     s = input()

#     answer = count_Pn(s, m, n)

#     print(answer)

import re

n = int(input())
_ = input()
string = input()

ioi = re.findall('I(?:OI)+', string)
count = 0

print(ioi)

for k in ioi:
	c = len(k) // 2 - n + 1
	if c > 0:
		count += c

print(count)