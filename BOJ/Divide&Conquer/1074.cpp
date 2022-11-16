//baekjoon 1074 silver1 Z 
// 

#include <iostream>
#include <algorithm>

using namespace std;

int n,r,c;
int tmp, result;

void Z(int size, int y, int x){
    if(y == r && x == c){
        result += tmp;
        return; //void문 종료
    }

    if(r < y + size && r >= y && c < x + size && c >= x){
        
        Z(size / 2, y, x); // 1사분면
        Z(size / 2, y, x + size/2); // 2사분면
        Z(size / 2, y + size/2, x); // 3사분면
        Z(size / 2, y + size/2, x + size/2); // 4사분면
    }else{
        tmp += size * size;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> r >> c;

    // int arr_size = pow(2, n);
    // int rc_arr[arr_size][arr_size]; // 2^n x 2^n 배열 생성

    Z((1<<n), 0, 0); // 시프트 연산 ^2을 대신 n > 1이므로

    cout << result << '\n';
    
    return 0;
}