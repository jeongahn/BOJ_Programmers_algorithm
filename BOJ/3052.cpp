// baekjoon 3052 bronze2 나머지

#include <iostream>

using namespace std;

int main(){
    int result = 10;
    int A[10];
    int B;
    
    for(int i = 0; i < 10; i++){
        cin >> B;
        A[i] = B % 42;
    }
    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10; j++){
            if(A[i] == A[j]){
                result--;
                break;
            }
        }
    }
    cout << result << '\n';

    return 0;
}