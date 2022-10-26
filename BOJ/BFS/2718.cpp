//baekjoon 2718 silver1 미로탐색
//BFS로 풀이
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int N, M;

bool visited[101][101];
int maze[101][101]; // 한줄씩 붙여서 입력이 들어오기때문에 string으로 배열
int dist[101][101]; // 해당 좌표까지의 거리를 담을 배열

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    int dir_x[4] = {-1,0,1,0}; // 4방향으로 탐색
    int dir_y[4] = {0,-1,0,1};

    while(!q.empty()){
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;

        q.pop(); // 중요!!

        for(int i = 0; i < 4; i++){
            int new_x = tmp_x + dir_x[i];
            int new_y = tmp_y + dir_y[i]; // 먼저 새로운 좌표를 구하고

            //후에 조건문에서 확인
            if((new_x >= 1 && new_x <= N) && (new_y >= 1 && new_y <= M)
                && !visited[new_x][new_y] && maze[new_x][new_y] == 1){

                visited[new_x][new_y] = 1;
                q.push(make_pair(new_x, new_y));
                dist[new_x][new_y] = dist[tmp_x][tmp_y] + 1;
                }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M;

    string s;
    
    for(int i = 1; i <= N; i++){
        cin >> s;

        for(int j = 1; j <= M; j++){
            maze[i][j] = s[j-1] - '0'; // 좌표는 1,1부터 시작하지만 문자열 인덱스는 0부터 시작하므로 -1
        }
    }

    BFS(1,1);

    cout << dist[N][M] + 1 << '\n'; // 최초 시작하는 지점부터 거리는 1로 포함 따라서 + 1를 해줌
    
    return 0;
}