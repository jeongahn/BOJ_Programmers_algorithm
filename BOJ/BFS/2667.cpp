//baekjoon 2667 silver1 단지번호붙이기
//
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define max 26

bool visited[max][max];
int graph[max][max];

int N, cnt; // 단지수 count

void BFS(int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = true;

    int dir_x[] = {-1, 0, 1, 0};
    int dir_y[] = {0, -1, 0, 1};

    while(!q.empty()){
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int new_x = tmp_x + dir_x[i];
            int new_y = tmp_y + dir_y[i];

            if((new_x >= 0 && new_y < N) && (new_y >= 0 && new_y < N) &&
                graph[new_x][new_y] == 1 && !visited[new_x][new_y]){
                visited[new_x][new_y] = true;
                q.push(make_pair(new_x, new_y));
                cnt++;
                }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> v; // 각 단지별 집의 수를 저장할 동적 배열
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            graph[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == 1 && !visited[i][j]){
                BFS(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << v.size() << '\n'; // 총단지수
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] + 1 << '\n'; // 각단지별 집 수
    }
    
    return 0;
}