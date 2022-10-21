//baekjoon 11050 bronze1 이항계수

#include <iostream>


using namespace std;

int fact(int n){
    if(n == 0){
        return 1;
    }
    int a = 1;
    for(int i = 1; i <= n; i++){
        a*=i;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;

    cin >> N >> M;

    if(N - M < M){
        M = N-M;
    }
    

    cout << (fact(N) / (fact(M)*fact(N-M))) << '\n';

    return 0;
}