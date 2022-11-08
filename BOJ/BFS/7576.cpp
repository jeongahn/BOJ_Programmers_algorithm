//baekjoon 7576 gold5 토마토 
//BFS

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define Max 1001
using namespace std;



int boxes[Max][Max];
int dist[Max][Max];

int dir_x[] = {-1,0,1,0};
int dir_y[] = {0,-1,0,1};

queue<pair<int, int>> q;

void BFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int new_y = y + dir_y[i];
            int new_x = x + dir_x[i];

            if((new_y >= 0 && new_y < Max) && (new_x >= 0 && new_x < Max) && (dist[new_y][new_x] == -1)
                ){
                    q.push(make_pair(new_y, new_x));
                    dist[new_y][new_x] = dist[y][x] + 1;
                }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N; // M : 가로 칸의 수, N : 세로 칸의 수
    int result = 0;
    
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> boxes[i][j];
            if(boxes[i][j] == 1){
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }else if(boxes[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }

    BFS();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dist[i][j] == -1){
                cout << -1 << '\n';
                return 0;
            }
            result = max(dist[i][j], result);
        }
    }

    cout << result << '\n';
    

    return 0;
}