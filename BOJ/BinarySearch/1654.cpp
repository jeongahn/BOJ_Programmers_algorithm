//baekjoon 1654 silver2 랜선 자르기
//이진탐색, 매개 변수 탐색


#include <iostream>


using namespace std;

int K, N, result;
int already[10001];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> K >> N;
    
    long left = 1, right = 0;
    for(int i = 0; i < K; i++){
        cin >> already[i];
        if(right < already[i]){
            right = already[i];
        }
    }

    while(left <= right){
        long mid = (right + left) / 2; //mid, right, left type이 long인 이유
        //랜선의 최대길이가 int 최대 범위 이기때문에 연산시에 최대범위를 벗어난다.
        int cnt = 0;

        for(int i = 0; i < K; i++){
            cnt += already[i] / mid;
        }
        
        if(cnt >= N){
            left = mid + 1;
            if(result < mid){
                result = mid;
            }
        }else{
            right = mid - 1;
        }
        
    }
    cout << result;
    
    return 0;
}