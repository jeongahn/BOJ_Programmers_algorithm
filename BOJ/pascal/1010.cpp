// baekjoon 1010 silver 5 다리 놓기

#include <iostream>

using namespace std;

/* 런타임 에러 수가 클수록 값이 너무 커진다
int combination(int M, int N)
{
    int i = 1;
    long long result = 1;

    if(N > M - N) N = M- N;

    while(i != N+1){
        result *= M--;
        result /= i++;
    }

    return result;
}
*/

int pas[31][31];

int pascal(int a, int b){
    pas[0][0] = 1;
    
    for(int i = 1; i < 31; i++){
        pas[i][0] = 1;

        for(int j = 1; j <= i; j++){
            pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
        }
    }

    int result = pas[a][b];

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    int N, M;

    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        cin >> N >> M;
        cout << pascal(M, N) << '\n';
    }

    return 0;
}