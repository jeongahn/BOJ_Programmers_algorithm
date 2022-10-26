//baekjoon 2839 silver4 설탕 배달

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;
    int tmp = N;
    
    int cnt = 0;
    while(N > 0){
        
        if(N % 5 == 3){
            cnt += (N / 5) + 1;
            break;
        }else{
            N -= 3;
            cnt++;
        }
    }
    if(tmp % 5 == 0){ // 3이 아닌 5만으로 나누는게 가능한 경우를 위해서 추가
        cout << (tmp / 5) << '\n';
    }else if(N < 0){
        cout << -1 << '\n';
    }else{
        cout << cnt << '\n';
    }
    
    return 0;
}