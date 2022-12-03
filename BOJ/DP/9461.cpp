//baekjoon 9461 silver3 파도반 수열
//

#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long dp[101];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    

    int testCase;

    cin >> testCase;

    int n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    
    for(int i = 0; i < testCase; i++){
        cin >> n;

        if(n > 3){
            for(int j = 4; j <= n; j++){
                dp[j] = dp[j-3] + dp[j-2];
            }
        }

        cout << dp[n] << '\n';
        
    }
    return 0;
    
}