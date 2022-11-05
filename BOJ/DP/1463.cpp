//baekjoon 1463 silver3 1로 만들기
//
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    // 1 - 0
    // 2 - 1
    // 3 - 1
    // 4 - 2
    // 5 - 3
    // 6 - 2 ( 6 % 2 == 0 and 6 % 3 == 0)
    // 7 - 3
    // 8 - 3
    // 9 - 2
    
    int arr[N+1];
    arr[1] = 0, arr[2] = 1, arr[3] = 1;

    for(int i = 4; i <= N; i++){
        if(i % 2 == 0 && i % 3 == 0){
            arr[i] = min(min(arr[i/2], arr[i/3]), arr[i-1]) + 1;
        }else if(i% 3 == 0){
            arr[i] = min(arr[i/3], arr[i-1]) + 1;
        }else if(i % 2 == 0){
            arr[i] = min(arr[i/2], arr[i-1]) + 1;
        }else{
            arr[i] = arr[i-1] + 1;
        }
    }

    cout<< arr[N] << '\n';
    return 0;
}