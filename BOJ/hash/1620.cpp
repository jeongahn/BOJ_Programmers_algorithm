//baekjoon 1620 silver4 나는 포켓몬마스터 이다솜
//
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int total, M;

    cin >> total >> M;
    unordered_map<int, string> m1;
    unordered_map<string, int> m2;
    
    for(int i = 1; i <= total; i++){
        string tmp;
        cin >> tmp;
        m1[i] = tmp;
        m2[tmp] = i;
    }
    for(int i = 1; i <= M; i++){
        string s;
        cin >> s;
        if(atoi(s.c_str()) != 0){
            cout << m1[atoi(s.c_str())] << '\n';
        }else{
            auto it = m2.find(s);
            cout << it->second << '\n';
        }
    }
    return 0;
}