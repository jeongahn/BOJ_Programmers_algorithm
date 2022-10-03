//baekjoon 2577 bronze 2 숫자의 개수

#include <iostream>

using namespace std;

int arr[10] = {0,};

int main(){
    int A, B, C;
    cin >> A >> B >> C;


    int result = A*B*C;

    while(result != 0){
        arr[(result%10)] += 1;
        result /= 10;
    }
    for(int i = 0; i < 10; i++){
         cout << arr[i] << '\n';
    }

    return 0;
    
}