// baekjoon 8958 bronze 2 OX퀴즈

#include <iostream>
#include <string>

using namespace std;

int main(){
    int testCase;
    int score = 0;
    string testResult;
    int seq_count = 0;
    
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> testResult;
        for(int j = 0; j < testResult.length(); j++){
            if(testResult[j] == 'O'){
                seq_count++;
                score += seq_count;
            }else if(testResult[j] == 'X'){
                seq_count = 0;
                continue;
            }
        }
        cout << score << '\n';
        score = 0;
        seq_count = 0;
    }

    return 0;
}