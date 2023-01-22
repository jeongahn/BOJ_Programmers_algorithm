#baekjoon 1316 silver5 그룹 단어 체커
# 23년 상반기 Foscar 알고리즘 스터디 3조 1주차 1번

testCase = input()
answer = 0

for i in range(int(testCase)):
    s = input()
    tmp = []
    check = True
    for j in range(0,len(s)):
        if s[j] not in tmp:
            tmp.append(s[j])
        else:
            if s[j] != s[j-1]:
                check = False
                break
    
    if check == True:
        answer += 1

print(answer)