//baekjoon 1929 silver3 소수 구하기

#include <iostream>
#include <cmath>
using namespace std;

int check[1000001] = {false,};

//시간복잡도가 O(N^2) 이어서 절대 통과 X
//그래서 nlogn인 '에라토스테네스의 체' 를 통해 소수 판정..
// bool check_Prime(int a){
//     int tmp = a;
    
//     for(int i = 2; i < a; i++){
//         if(tmp % i == 0){
//             return false;
//         }
//     }

//     return true;
// }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;

    cin >> M >> N;

    check[0] = check[1] = true;
    
    for(int i = 2; i <= sqrt(N); i++){
        if(check[i] == false){
            for(int j = i + i; j <= N; j += i){
                check[j] = true;
            }
        }
    }
    for(int i = M; i <= N; i++){
        if(!check[i]) cout << i << '\n';
    }
    
    return 0;
}