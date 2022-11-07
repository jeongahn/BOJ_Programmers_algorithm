//baekjoon 11723 silver5 집합
// 비트 마스킹 문제... 문자열 추가와 제거로 풀다가 시간초과;

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M;

    cin >> M;
    
    int ele, bit = 0;
    
    for(int i = 0; i < M; i++){
        string order;
        cin >> order;
        if(order == "add"){
            cin >> ele;
            bit |= (1 << ele);
        }else if(order == "check"){
            cin >> ele;
            if (bit & (1 << ele)){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
            
        }else if(order == "remove"){
            cin >> ele;
            bit &= ~(1 << ele);
        }else if(order == "toggle"){
            cin >> ele;
            // ^ -> xor 연산
            bit ^= (1 << ele);
        }else if(order == "all"){
            bit = (1 << 21) - 1;
            // 10000 - 1 == 1111
        }else if(order == "empty"){
            bit = 0;
        }     
    }

    return 0;
}