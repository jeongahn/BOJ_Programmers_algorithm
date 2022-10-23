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

// 어떤 수 N의 양의 제곱근 이하의 수들로 N을 나눠서 한 번이라도 나누어떨어지면 합성수, 아니면 소수라고 판정

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;

    cin >> M >> N;

    check[0] = check[1] = true;
    
    for(int i = 2; i <= sqrt(N); i++){ // sqrt - 제곱근을 구해주는 함수
        if(check[i] == false){ // 예를 들어 2는 소수에 해당하는데 2의 배수들은 소수가 아니기에 그 배수에 해당하는 수들을 제거해준다
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