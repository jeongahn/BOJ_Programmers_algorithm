//baekjoon 17626 silver3 Four Squares

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int dp[50001];

void make_DP(int n){
    for(int i = 1; i*i <= n; i++){
        if(dp[n] == 0){
            dp[n] = dp[i*i] + dp[n - i*i];
        }else{
            dp[n] = min(dp[n], dp[i*i] + dp[n - i*i]);
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i*i <= n; i++){
        dp[i*i] = 1;
    }

    for(int i = 2; i <= n; i++){
        if(dp[i] == 0){
            make_DP(i);
        }else{
            continue;
        }
    }
    
    cout << dp[n] << '\n';

    return 0;
}