//baekjoon 2805 silver2 나무 자르기

#include <iostream>


using namespace std;

int N, M, result;
int trees[1000001];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    long left = 1, mid = 0 , right = 0;
    
    for(int i = 0; i < N; i++){
        cin >> trees[i];
        if(right < trees[i]){
            right = trees[i];
        }
    }

    
    while(left <= right){
        mid = (left + right) / 2;

        
        long long mod = 0;
        for(int i = 0; i < N; i++){
            if(trees[i] > mid){
                mod += (trees[i] - mid);   
            }
        }

        if(mod == M){
            result = mid;
            break;
        }else if(mod > M){ // 나무를 자르고 가져갈때 원하는 만큼의 나무가 안남는 경우가 발생
            //그래서 적어도 M 이상의 나무를 가져가야 되므로 잘랐을때 남은 나무의 길이가 M보다는 커야 한다.
            if(result < mid){
                result = mid;
            }
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << result << '\n';
    
    
    return 0;
}