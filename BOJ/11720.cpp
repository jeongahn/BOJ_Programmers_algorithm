//baekjoon 11720 bronze 4 숫자의 합

#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    string tmp;
    int sum = 0;
    
    cin >> N >> tmp;

    
    for(int i = 0; i < N; i++){
        //cout << int(tmp[i]) << '\n';
        sum += (int(tmp[i]) - 48) ;
    }
    cout << sum << '\n';

    return 0;
}