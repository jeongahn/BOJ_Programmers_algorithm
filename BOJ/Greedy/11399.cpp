//baekjoon 11399 silver4 ATM

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int arr[N];
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int tmp = arr[0];
    
    int min_sum = 0;
    
    min_sum += tmp;
    
    for(int i = 1; i < N; i++){
        tmp += arr[i];
        min_sum += tmp;
    }
    
    cout << min_sum << '\n';
    
    return 0;
   
}