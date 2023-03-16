//baekjoon gold4 테트로미노
#include <iostream>
#include <algorithm>

#define Max 501


using namespace std;
int N,M;
int visited[Max][Max] = {0,};
int board[Max][Max] = {0,};
int answer = 0;

int dir_x[4] = {-1, 0, 0, 1};
int dir_y[4] = {0, -1, 1, 0};

void DFS(int y, int x, int cnt, int tmp_sum){
    
    if(cnt == 4){
        if(answer < tmp_sum){
            answer = tmp_sum;
        }
        return;
    }


    for(int i = 0; i < 4; i++){
        int new_y = y + dir_y[i];
        int new_x = x + dir_x[i];

        if(new_y < 0 || new_y >= N || new_x < 0 || new_x >= M || visited[new_y][new_x]){
            continue;
        }
        visited[new_y][new_x] = 1;
        DFS(new_y, new_x, cnt+1, tmp_sum + board[new_y][new_x]);
        visited[new_y][new_x] = 0; // 백트래킹
    }

    if(y-1 >= 0 && x-1 >= 0 && y+1 < N){ // ㅓ
        answer = max(answer, (board[y-1][x] + board[y][x-1] + board[y][x] + board[y+1][x]));
    }
    if(y-1 >= 0 && x+1 < M && y+1 < N){ // ㅏ
        answer = max(answer, (board[y-1][x] + board[y][x+1] + board[y][x] + board[y+1][x]));
    }
    if(x-1 >= 0 && x+1 < M && y+1 < N){ // ㅗ
        answer = max(answer, (board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+1][x+1]));
    }
    if(x-1 >= 0 && x+1 < M && y+1 < N){ // ㅜ
        answer= max(answer, (board[y][x-1] + board[y][x] + board[y][x+1] + board[y+1][x]));
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = 1;
            DFS(i,j,1, board[i][j]);
            visited[i][j] = 0;
        }
    }
    cout << answer << '\n';
}