// baekjoon 2675 bronze 2 문자열 반복

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase, R; // (1 <= testCase <= 1000) , 1<= R <= 8
    string S;
    string result = "";
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> R >> S;
        for(int j = 0; j < S.length(); j++){
            for(int r = 0; r < R; r++){
                result += S[j];
            }
        }
        cout << result << '\n';
        result = "";
    }

    return 0;
    
}