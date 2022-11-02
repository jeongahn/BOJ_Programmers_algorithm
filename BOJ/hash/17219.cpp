//baekjoon 17219 silver4 비밀번호 찾기
//
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;
    unordered_map<string, string> um;

    for(int i = 0; i < N; i++){
        string address, pw;
        cin >> address >> pw;

        um[address] = pw;
    }
    for(int j = 0; j < M; j++){
        string want;
        cin >> want;

        cout << um[want] << '\n';
    }
    
    return 0;
}