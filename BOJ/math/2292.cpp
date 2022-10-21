//baekjoon 2292 bronze2 벌집

#include <iostream>


using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double N; // 91일때와 92일때 int일 경우 몫이 똑같이 15가 된다.

    cin >> N;

    int count = 0;

    double tmp = N;

    tmp = (tmp - 1) / 6;
    
    for(int i = 1; tmp > 0; i++){
        tmp -= i;
        count++;
    }

    cout << count + 1 << '\n';
    
    return 0;
}