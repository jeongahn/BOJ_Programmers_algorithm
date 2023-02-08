# // baekjoon 16120 gold4 PPAP
# // 23년 상반기 Foscar 알고리즘 스터디 5조 2주차 4번
# // 그리디 알고리즘


w = input()
stack = []
ppap = ["P", "P", "A", "P"]
for i in range(len(w)):
    stack.append(w[i])
    if stack[-4:] == ppap:
        for _ in range(4):
            stack.pop()
        stack.append("P")
if stack == ppap or stack == ["P"]:
    print("PPAP")
else:
    print("NP")
