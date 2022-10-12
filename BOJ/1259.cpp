//baekjoon 1259 bronze 1 팰린드롬수

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;

    while(1){
        cin >> a;

        if(stoi(a) == 0){
            break;
        }else{
            int mid = a.length() / 2;
            int end = a.length() - 1;
            int flag = 0;
            
            for(int i = 0; i <= mid; i++){
                if(a[i] != a[end--]){
                    cout << "no" << '\n';
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cout << "yes" << '\n';
            }
        }
    }

    return 0;
}