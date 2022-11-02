//baekjoon 1676 silver5 팩토리얼 0의 개수

#include <iostream>
#include <algorithm>

using namespace std;

int arr[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    if(N > 0){
        for(int i = 1; i <= N; i++){
            int zero_cnt = 0;
            int tmp = i;

            while(1){
                if(tmp % 5 == 0){
                    zero_cnt++;
                    tmp /= 5;
                }else{
                    break;
                }
            }

            arr[i] = zero_cnt;
        }
    }
    int result = 0;
    for(int i = 1; i <= N; i++) result += arr[i];
    
    cout << result << '\n';
    
    return 0;
   
}