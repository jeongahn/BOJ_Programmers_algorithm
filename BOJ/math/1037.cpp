//baekjoon 1037 bronze 1 약수
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int div_num, N;
    int A = 1;
    cin >> div_num; // divisor_num;

    int div_arr[div_num];
    
    for(int i = 0; i < div_num; i++){
        cin >> N;
        div_arr[i] = N;
    }

    sort(div_arr, div_arr + div_num);

    // if((sizeof(div_arr) / sizeof(int)) == 1){
    //     A = div_arr[0] * div_arr[0];
    // }else{
    //     A = div_arr[0];
    //     for(int i = 1; i < div_num; i++){
    //         if(A % div_arr[i] == 0){
    //             continue;
    //         }else{
    //             A *= div_arr[i];
    //         }
    //     }
    // }
    
    A = div_arr[0] * div_arr[div_num-1];
    

    cout << A << '\n';

    return 0;
}