//baekjoon 2630 silver2 색종이 만들기
//
#include <iostream>

using namespace std;

int square[128][128];
int white_n, blue_n;

void DFS(int y, int x, int N){
    bool zero = true, one = true;

    for(int i = y; i < y + N; i++){
        for(int j = x; j < x + N; j++){
            if(square[i][j] == 1) zero = false;
            if(square[i][j] == 0) one = false;
        }
    }
    // 계속 4등분을 하며 탐색을 하다가 zero가 true이거나 one이 true이면
    // 흰색 종이 개수 또는 파란색 종이를 증가시키고 return
    if(zero == true){
        white_n++;
        return; 
    }else if(one == true){
        blue_n++;
        return;
    }

    // 4등분을 위한 재귀함수, 왼위-왼아래-오른쪽위-오른쪽아래(4등분)
    DFS(y, x, N / 2);
    DFS(y + N/2, x, N/2);
    DFS(y, x + N/2, N/2);
    DFS(y + N/2, x + N/2, N/2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> square[i][j];
        }
    }

    DFS(0,0,N);

    cout << white_n << '\n' << blue_n << '\n';
    
    
    return 0;
}