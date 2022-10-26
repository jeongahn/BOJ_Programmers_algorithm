//baekjoon 2606 silver3 바이러스
//
#include <iostream>
#include <queue>

using namespace std;
#define max 101

bool visited[max];
int graph[max][max];

int N, M, cnt; // 1번 컴퓨터로 인해 전염된 컴퓨터를 세야되므로

void BFS(int a){
    queue<int> q;
    visited[a] = true;
    q.push(a);

    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i = 1; i <= N; i++){
            if(!visited[i] && graph[tmp][i] == 1){
                cnt++; //
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    BFS(1);

    cout << cnt << '\n';
    
    return 0;
}