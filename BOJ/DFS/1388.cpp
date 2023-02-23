// # baekjoon 1388 silver4 바닥장식
// # 23년 상반기 Foscar 알고리즘 스터디 1조 4주차 1번
// # DFS

#include <iostream>
#define Max 51

using namespace std;

int N, M, total;
char tile[Max][Max];
int visited[Max][Max] = {0,};


void DFS(int y, int x){
    if(visited[y][x] == 1 || y >= N || x >= M){
        return; // 재귀 종료 조건
    }else{
        visited[y][x] = 1;
        if(tile[y][x] == '-'){
            if(tile[y][x + 1] == '|'){
                return;
            }
            DFS(y, x + 1);
        }else{
            if(tile[y + 1][x] == '-'){
                return;
            }
            DFS(y + 1, x);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    total = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tile[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0){
                total += 1;
                DFS(i, j);
            }
        }
    }

    cout << total << '\n';

    return 0;
}