//baekjoon 10026 gold5 적록색약
//
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

#define max 101

int square[max][max];
int visited[max][max];
int N, cnt_R, cnt_B, cnt_G;

void BFS(int y, int x, char color){
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    int dir_y[] = {-1,0,1,0};
    int dir_x[] = {0,-1,0,1};
    
    while(!q.empty()){
        int tmp_y = q.front().first;
        int tmp_x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int new_y = tmp_y + dir_y[i];
            int new_x = tmp_x + dir_x[i];

            if((new_x >= 0 && new_x < N) && (new_y >= 0 && new_y < N) &&
                !visited[new_y][new_x] && square[new_y][new_x] == color){
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

    cin >> N;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            square[i][j] = s[j];
        }
    }
    
    
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                if(square[i][j] == 'R'){
                    BFS(i, j, 'R');
                    cnt_R++;    
                }else if(square[i][j] == 'G'){
                    BFS(i, j, 'G');
                    cnt_G++;
                }else{
                    BFS(i, j, 'B');
                    cnt_B++;
                }
                
            }
        }
    }

    cout << cnt_R + cnt_G + cnt_B << " ";

    cnt_R = 0;
    cnt_G = 0;
    cnt_B = 0;
    
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(square[i][j] == 'G') square[i][j] = 'R';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                if(square[i][j] == 'R'){
                    BFS(i, j, 'R');
                    cnt_R++;    
                }else{
                    BFS(i, j, 'B');
                    cnt_B++;
                }
            }
        }
    }
    
    cout << cnt_R + cnt_B << '\n';
    
    return 0;
}