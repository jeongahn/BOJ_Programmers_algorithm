#baekjoon 4673 silver5 셀프 넘버
# 23년 상반기 Foscar 알고리즘 스터디 1조 1주차 4번

# 나는 에라스토네스의 체를 이용함(맞나.? ㅋㅋㅋㅋㅋㅋ)


numbers = [0 for i in range(10001)]

for i in range(1, 10001):
    tmp = i
    dn = tmp
    while(tmp > 0):
        dn += int(tmp%10)
        tmp /= 10
    if dn <= 10000:

        numbers[dn] = 1

for i in range(1,len(numbers)):
    if numbers[i] == 0:
        print(i)

