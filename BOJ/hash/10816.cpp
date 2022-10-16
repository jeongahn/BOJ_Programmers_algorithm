//baekjoon 10816 silver4 숫자 카드2

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    unordered_map<int, int> card;

    int N, num1, M, num2;

    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> num1;
        card[num1]++;
    }
    cin >> M;
    
    for(int i = 0; i < M; i++){
        cin >> num2;
        cout << card[num2] << ' ';
    }
    cout << '\n';

    return 0;

    
}