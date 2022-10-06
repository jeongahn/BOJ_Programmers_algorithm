//baekjoon 2869 silver 5 달팽이는 올라가고 싶다
//반복문 사용 X

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B, V;
    cin >> A >> B >> V;
    int curr = 0;
    int days = 0;
    int tmp = A - B;
    
    if(A == V){
        cout << 1 << '\n';
    }else if((V - A) % (A - B) != 0){
        cout << ((V - A) / (A - B)) + 2 << '\n';
    }else{
        cout << ((V - A) / (A - B)) + 1 << '\n';
    }
    

    return 0;
}