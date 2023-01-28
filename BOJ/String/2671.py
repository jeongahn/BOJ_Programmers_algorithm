# baekjoon 2671 gold5 잠수함식별
# 23년 상반기 Foscar 알고리즘 스터디 5조 1주차 2번


# 1번 re 모듈 사용
# import re

# sound = input()

# pattern = re.compile('(100+1+|01)+')

# result = pattern.fullmatch(sound)

# if result:
#     print("SUBMARINE")
# else:
#     print("NOISE")

# 2번 구현

sound = input()

def check():
    i = 0
    s = len(sound)

    while(i < s):
        if sound[i] == '0': # 01부터 시작하면
            if(i + 1 >= s):
                return False # 최소 길이 2이므로 01
            if(sound[i+1] != '1'):
                return False
            i += 2 # 01이면 인덱스 2개를 봤으므로 다음부터는 2번 인덱스부터 확인
        else:
            if(i+3 >= s):
                return False #1 00 1 최소 길이 4
            if(not(sound[i+1] == '0' and sound[i+2] == '0')):
                return False
            i += 1
            while(i < s and sound[i] == '0'):
                i += 1 #1 00 1에서 1을 지나고 마지막 1이 오기전 계속 0이 올 때

            if(i >= s):
                return False # 1 00~ 0이 계속 오다가 결국 1이 오지 않으면 noise
            i+=1 #결국 1 00 다음 1이 오면
            while(i < s and sound[i] == '1'):
                if(i + 2 < s and sound[i+1] == '0' and sound[i+2] == '0'):
                    break # 1 00~ 1~이기 때문에 1 00 1 00 패턴이 올 수 있다 그런 경우 다시 위에서 부터 순회
                i+=1    
    return True


def solution():
    if(check()):
        print("SUBMARINE")
    else:
        print("NOISE")

solution()        
        

