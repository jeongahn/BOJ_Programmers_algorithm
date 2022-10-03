//baekjoon 2908 bronze 2 상수
#include <iostream>
#include <string>
using namespace std;

int main(){
    string Num_1, Num_2;

    cin >> Num_1 >> Num_2;
    string result;

    for(int i = 2; i >= 0; i--){
        if(Num_1[i] > Num_2[i]){
            result = Num_1;
            break;
        }else if(Num_2[i] > Num_1[i]){
            result = Num_2;
            break;
        }
    }

    cout << result[2] << result[1] << result[0] << '\n';
    return 0;
}