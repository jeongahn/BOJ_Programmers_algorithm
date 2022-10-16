//baekjoon 1157 bronze 1 단어 공부

#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;

    cin >> S;

    
    char alphabet_Arr[26];
    int count_Arr[26];
    
    for(int i = 0; i < 26; i++){
        alphabet_Arr[i] = char(i + 65);
        count_Arr[i] = 0;
    }
    //toupper 함수로 소문자를 대문자로 변환 및 해당 문자 counting
    for(int i = 0; i < S.size(); i++){
        S[i] = toupper(S[i]);
        count_Arr[int((S[i]) - 65)] += 1;
    }
    int flag = 0;
    int max = 0;
    int idx = 0;
    
    for(int i = 0; i < 26; i++){
        // cout << count_Arr[i] << '\n';
        if(max < count_Arr[i]){
            max = count_Arr[i];
            idx = i;
            flag = 0;
            continue;
        }else if(max == count_Arr[i]){
            flag = 1;
        }
    }
    if(flag == 1){
        cout << '?' << '\n';
    }else{
        cout << alphabet_Arr[idx] << '\n';
    }

    

    return 0;
}