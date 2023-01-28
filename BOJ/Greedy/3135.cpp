// baekjoon 3135 silver5 라디오
// 23년 상반기 Foscar 알고리즘 스터디 2조 2주차 4번
// 그리디 알고리즘


#include <iostream>
#include <cmath>

using namespace std;




int main(){
    int a,b,n,apt;

    cin >> a >> b;

    cin >> n;

    int min_cnt = abs(a - b);

    for(int i = 0; i < n; i++){
        cin >> apt;
        min_cnt = min(min_cnt, abs(apt - b) + 1);
    }

    cout << min_cnt << '\n';

}