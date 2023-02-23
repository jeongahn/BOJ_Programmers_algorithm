// # baekjoon 10799 silver2 쇠막대기
// # 23년 상반기 Foscar 알고리즘 스터디 5조 3주차 2번
// # 스택, 구현

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define Max 101

using namespace std;


int N, K, L, X;
char C;
int board[Max][Max] = {0,};
int dir_y[] = {0,1,0,-1}; // 우, 하, 좌, 상 순서 
int dir_x[] = {1,0,-1,0};
int main(){
    cin >> N;

    // 사과 위치
    cin >> K;

    int x,y;

    for(int i = 0; i < K; i++){
        cin >> y >> x;
        board[y][x] = 1;    
    }

    cin >> L;

    queue<pair<int, char>> dir_time;

    for(int i = 0; i < L; i++){
        cin >> X >> C;
        dir_time.push(make_pair(X, C));
    }

    int time = dir_time.front().first;
    int dir = dir_time.front().second;

    dir_time.pop();
    int dir_idx = 0;


}
