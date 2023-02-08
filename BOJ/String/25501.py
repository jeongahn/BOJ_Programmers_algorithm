# // baekjoon 25501 bronze2 재귀의 귀재
# // 23년 상반기 Foscar 알고리즘 스터디 1조 3주차 2번
# // 재귀

n = int(input())
cnt = 0

def recursion(s, l, r):
    global cnt
    if l >= r:
        cnt += 1
        return 1
    elif s[l] != s[r]:
        cnt+=1
        return 0
    else:
        cnt+= 1
        return recursion(s, l+1, r - 1)

def isPalindrome(s):
    return recursion(s, 0, len(s) - 1)

if __name__ == "__main__":
    for i in range(n):
        s = input()
        cnt = 0
        answer = isPalindrome(s)
        print(answer, cnt)
