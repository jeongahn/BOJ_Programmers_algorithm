//baekjoon 1012 silver2 유기농 배추
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define max 52

bool visited[max][max];
int map[max][max];

int M, N, K, cnt; // 가로, 세로, 심어진 배추의 개수, 지렁이수 count

void BFS(int x, int y){
    queue<pair<int, int>> q;

    visited[x][y] = true;
    q.push(make_pair(x,y));

    int dir_x[] = {-1,0,1,0};
    int dir_y[] = {0,-1,0,1};
    
    while(!q.empty()){
        int tmp_y = q.front().first;
        int tmp_x = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int new_y = tmp_y + dir_y[i];
            int new_x = tmp_x + dir_x[i];

            if((new_x >= 0 && new_x < M) && (new_y >= 0 && new_y < N) &&
                !visited[new_y][new_x] && map[new_y][new_x] == 1){
                visited[new_y][new_x] = true;
                q.push(make_pair(new_y, new_x));
                }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase;

    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> M >> N >> K; // 세로 좌표 순으로 해야되는게 맞는건데..
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        for(int j = 0; j < K; j++){
            int a, b;
            cin >> a >> b;
            map[b][a] = 1;
        }

        for(int j = 0; j < N; j++){
            for(int r = 0; r < M; r++){
                if(map[j][r] == 1 && !visited[j][r]){
                    BFS(j, r);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        cnt = 0;        
    }
    
    return 0;
}