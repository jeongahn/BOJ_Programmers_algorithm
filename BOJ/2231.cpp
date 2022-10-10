//baekjoon 2231 bronze 2 분해합

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;


    for(int i = 1; i <= N; i++){
        int tmp = i;
        int sum = 0;
        sum += tmp;
        while(tmp != 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        
        if(i == N){
            cout << 0 << '\n';
            break;
        }
        if(sum == N){
            cout << i << '\n';
            break;
        }
        
    }
    return 0;
}