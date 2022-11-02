//baekjoon 1107 gold5 리모컨
//브루트 포스 문제

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool remote[10] = {false, };


bool check(int tmp){ // 0부터 999999까지 숫자중 해당 숫자가 없어진 버튼을 제외한 나머지 버튼으로 누를수 있는 숫자인지 체크
    string s = to_string(tmp);
    for(int i = 0; i < s.length(); i++){
        if(remote[s[i] - '0']){
            return false; // 만약 해당 숫자가 버튼으로 누를수 없다면 false
        }
    }
    return true; // 누를수 있다면 true
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int N, M, button;
    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> button;
        remote[button] = true;
    }

    string s = to_string(N); // 문자열로 받아서 각각의 숫자가 없는 버튼인지 확인한다.
    
    int f_min = abs(N-100); // 100부터 시작하기 때문에 +, - 버튼으로만 해당 채널로 간다면 누를수 있는 최대 값은 abs(N-100)
    // 최댓값을 default로 줌
    
    for(int i = 0; i <= 1000000; i++){
        if(check(i)){
            int s_min = abs(N-i) + to_string(i).length();
            f_min = min(f_min, s_min); // 가장 최솟값을 모든 경우의 수를 돌며 구한다
        }
    }
    

    cout << f_min << '\n';
    return 0;
}