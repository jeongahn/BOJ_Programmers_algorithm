#include <iostream>

using namespace std;


int a[1001];

int fibo(int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else{
        for(int i = 3; i <= n; i++){
            a[i] = (a[i-1] + a[i-2]) % 10007;
        }
        return a[n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    a[1] = 1;
    a[2] = 2;

    cout << fibo(n) << '\n';
}