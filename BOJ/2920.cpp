// baekjoon 2920 bronze 2 음계

#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    int tmp = 0;
    string result;

    
    for(int i = 0; i < 8; i++){
        cin >> num;
        if(i == 0){
            tmp = num;
            continue;
        }else{
            if(tmp == num - 1){
                result = "ascending";
                tmp = num;
            }else if(tmp == num + 1){
                result = "descending";
                tmp = num;
            }else{
                result = "mixed";
                break;
            }
        }
    }
    cout << result << '\n';

    return 0;
}