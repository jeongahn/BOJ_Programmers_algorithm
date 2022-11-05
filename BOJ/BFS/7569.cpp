//baekjoon 7569 gold5 토마토
//
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int boxes[101][101][101];
int visited[101][101][101];
int dist[101][101][101];
int M, N, H;
queue<pair<pair<int,int>, int>> q;
void BFS(){
    
    int dx[] = {-1, 1, 0, 0, 0, 0};
    int dy[] = {0, 0, -1, 1, 0, 0};
    int dz[] = {0, 0, 0, 0, -1, 1};

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if(nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if(dist[nx][ny][nz] >= 0) continue; // dist가 -1일 경우만 밑에 코드가 실행
			q.push(make_pair(make_pair(nx,ny),nz));
			dist[nx][ny][nz] = dist[x][y][z] + 1;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int r = 0; r < M; r++){
                cin >> boxes[j][r][i];
                if(boxes[j][r][i] == 1){
                    q.push(make_pair(make_pair(j,r),i));
                }else if(boxes[j][r][i] == 0){
                    dist[j][r][i] = -1;
                }
                
            }
        }
    }
    int result = 0;
    
    BFS();
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int r = 0; r < M; r++){
                if(dist[j][r][i] == -1){
                    cout << -1 << '\n';
                    return 0;
                }
                result = max(dist[j][r][i], result);
            }
        }
        
    } 
    cout << result << '\n';
    return 0;
}