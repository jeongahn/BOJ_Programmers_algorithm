//baekjoon 4963 silver2 섬의 개수
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[51][51];
int visited[51][51];

int dir_x[] = {1,1,1,0,0,-1,-1,-1};
int dir_y[] = {-1,0,1,-1,1,1,0,-1};
int w, h;

void dfs(int y, int x){

    for(int i = 0; i < 8; i++){
        int next_y = y + dir_y[i];
        int next_x = x + dir_x[i];

        if(next_x >= 0 && next_x < w && next_y >= 0 && next_y < h &&
            !visited[next_y][next_x] && map[next_y][next_x]){
            visited[next_y][next_x] = true;
            dfs(next_y,next_x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    while(1){
        
        int cnt = 0;
        cin >> w >> h;

        if(!w && !h) break;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!visited[i][j] && map[i][j]){
                    visited[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        memset(visited,0,sizeof(visited));
    }
    
    
    return 0;
    
}