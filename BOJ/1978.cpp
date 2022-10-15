//baekjoon 1978 silver5 소수 찾기

#include <iostream>

using namespace std;

int main(){
    int N;
    int p_num;

    cin >> N;
    int count = 0;
    
    for(int i = 0; i < N; i++){
        cin >> p_num;
        int a, b;
        a = 2;
        b = p_num - 1; // 자기 자신을 제외한 그 아래의 숫자를 계속 나누어 보기 위해
        if(p_num == 1){
            continue;
        }
        while(1){
            if(a <= b){ // 수 -1 까지 나누어 보는 조건
                if(p_num % a == 0){ // p_num이 나누어 떨어지면 소수가 아니다
                    break;
                }else{
                    a++;
                }
            }else{ // a가 b보다 커질때 까지 나누어떨어지지 않으면 소수
                count++;
                break;
            }        
        }
    }

    cout << count << '\n';

    return 0;
    
}