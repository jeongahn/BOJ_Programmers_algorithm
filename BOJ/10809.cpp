//baekjoon 10809 standard 알파벳 찾기

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool overlap_check(string S, char a, int idx){
    for(int i = 0; i < idx; i++){
        if(S[i] == a){
            return true;
        }
    }
    return false;
}
int findIndex(char arr[], int n, char target)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main(){
    string S;

    cin >> S;

    char alphabet_Arr[26];
    int location_Arr[26];

    for(int i = 0; i < 26; i++){
        alphabet_Arr[i] = char(i + 97);
        location_Arr[i] = -1;
    }
    int loc = 0;
    for(int i = 0; i < S.size(); i++){
        if(overlap_check(S, S[i], i) == true){
            continue;
        }else{
            loc = findIndex(alphabet_Arr, 26, S[i]);
            // cout << loc << '\n'; echo checking
            location_Arr[loc] = i;
        }
    }
    for(int i = 0; i < 26; i++){
        cout << location_Arr[i] << " ";
    }
    cout << '\n';

    return 0;
}