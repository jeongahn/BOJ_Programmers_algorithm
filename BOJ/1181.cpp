// baekjoon 1181번 silver 5 단어 정렬

#include <iostream>
#include <string>
#include <algorithm>

int N;

using namespace std;

bool compare(string a, string b){ // compare 함수 구현, 길이 우선 그리고 사이즈가 같으면 사전 순서
    if(a.size() == b.size()){
        return a < b;
    }else{
        return a.size() < b.size();
    }
}

bool check(string s, string arr[]){ // 중복 제거 해주기 위한 함수 구현
    for(int i = 0; i < N ; i++){
        if(arr[i] == s){
            return true;
        }
    }
    return false;
}
int main(){
    
    cin >> N;

    string arr[N];
    
    string s;

    for(int i = 0; i < N; i++){
        cin >> s;
        if(check(s, arr) == true){
            continue;
        }else{
            arr[i] = s;
        }
    }
    sort(arr, arr+N, compare);
    
    for(int i = 0; i < N; i++){
        if(arr[i].size() == 0){ // 빈 문장 출력 X
            continue;
        }else{
            cout << arr[i] << '\n';
        }
    }
    
    return 0;
}