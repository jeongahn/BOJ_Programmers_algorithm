//baekjoon 2579 silver3 계단오르기  

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int dp[301];
int blocks[301];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    
    int point;
    for(int i = 1; i <= n; i++){
        cin >> point;
        blocks[i] = point;
    }
    
    dp[0] = 0;
    dp[1] = blocks[1];
    dp[2] = blocks[1] + blocks[2];

    
    
    for(int i = 3; i <= n; i++){
        // 바로 전 값을 더한다면 그 경우는 바로 전값에 또 그 전 값이 연속으로 올수 없기 때문에
        // 그 전전의 누적값에 전값을 더한 경우와 두번째 전 누적값중 큰값과 더한다.
        dp[i] = blocks[i] + max(dp[i-2], dp[i-3] + blocks[i-1]);
    }

    cout << dp[n] << '\n';

    return 0;
    
}