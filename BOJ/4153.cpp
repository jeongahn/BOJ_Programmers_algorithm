//baekjoon 4153 bronze3 직각삼각형

#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int arr[3];
    
    while(1){
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr, arr + 3);
        
        if(arr[0] + arr[1] + arr[2] == 0){
            break;
        }
        if((arr[0]*arr[0]) + (arr[1]*arr[1]) == (arr[2]*arr[2])){
            cout << "right" << '\n';
        }else{
            cout << "wrong" << '\n';
        }
    }

    return 0;
}