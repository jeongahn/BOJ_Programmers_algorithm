//baekjoon 2468 silver1 안전 영역
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[101][101];
int visited[101][101];

int dir_x[] = {0,1,0,-1};
int dir_y[] = {1,0,-1,0};
int n;

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];

        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;

        if(!visited[next_y][next_x]){
            visited[next_y][next_x] = 1;
            dfs(next_y, next_x);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int safe_bound = 0;
    
    
    for(int i = 1; i <= 100; i++){
        memset(visited, 0, sizeof(visited));
        int tmp = 0;
        for(int j = 0; j < n; j++){
            for(int r = 0; r < n; r++){
                if(map[j][r] <= i){
                    visited[j][r] = 1;
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int r = 0; r < n; r++){
                if(!visited[j][r]){
                    dfs(j, r);
                    tmp++;
                }
            }
        }
        safe_bound = max(safe_bound, tmp);
    }
    if(safe_bound == 0) safe_bound = 1;
    cout << safe_bound << '\n';
    
    return 0;
    
}