//baekjoon 11727 silver3 2xn 타일링2
//https://dontdiethere.tistory.com/64

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;

    cin >> n;

    
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }      
    

    cout << dp[n] << '\n';
    
    return 0;
    
}