// baekjoon 16953 silver2 A->B
// 23년 상반기 Foscar 알고리즘 스터디 4조 2주차 3번
// 그리디 알고리즘


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long a, b;
long min_cal = 11111111111;


void DFS(long alpha, long cnt){
    if(alpha > b){
        return;
    }
    if(alpha == b){
        min_cal = min(min_cal, cnt);
        return;
    }
    DFS(alpha*2, cnt+1);
    DFS((alpha*10)+1, cnt+1);
      
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    

    DFS(a, 1);

    cout << (min_cal == 11111111111 ? -1 : min_cal)  << '\n';


}