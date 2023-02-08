// baekjoon 10994 silver2 로또
// 23년 상반기 Foscar 알고리즘 스터디 3조 3주차 4번
// 재귀

#include <iostream>
#define len 13
using namespace std;


int S[len];
int lotto[6];
int k;

void recursive(int start, int length){
    if(length == 6){
        for(int i = 0; i < 6; i++){
            cout << lotto[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = start; i < k; i++){
        lotto[length] = S[i];
        recursive(i+1, length+1);
    }
}




int main(){
    

    
    while(true){
        cin >> k;

        if(k == 0){
            break;
        }

        for(int i = 0; i < k; i++){
            cin >> S[i];
        }
        recursive(0,0);
        cout << '\n';
    }
        
    return 0;

}