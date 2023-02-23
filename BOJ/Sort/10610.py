# baekjoon 10610 silver4 30
# 23년 상반기 Foscar 알고리즘 스터디 4조 5주차 1번
# Sort
# 핵심 포인트 : 3의 배수가 되기 위해선 각 자리수의 합이 3의 배수이면 3의 배수이다.

if __name__ == "__main__":
    n = list(input())
    n.sort(reverse=True)
    sum = 0
    for i in n:
        sum += int(i)
    if sum % 3 != 0 or "0" not in n:
        print(-1)
    else:
        print("".join(n))
