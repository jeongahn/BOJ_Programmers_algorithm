//baekjoon 1260 silver2 DFS와 BFS
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
#define max 1001


int graph[max][max];
bool visited[max];
int N, M, V;

//DFS 재귀함수
// void DFS(int v){
//     visited[v] = true;
//     cout << v << " ";

//     for(int i = 0; i < graph[v].size(); i++){
//         int next = graph[v][i];

//         if(!visited[next]){
//             DFS(next);
//         }
//     }
// }
//DFS stack
void DFS(int v){
    stack<int> s;
    s.push(v);
    visited[v] = true;
    cout << v << " ";

    while(!s.empty()){
        int curr = s.top();
        s.pop();

        for(int i = 1; i <= N; i++){
            if(!graph[curr][i]) continue;
            int next = graph[curr][i];
            
            if(!visited[next]){
                cout << next << " ";
                visited[next] = true;

                s.push(curr);
                s.push(next);
                break;
            }
        }
    }
}

void BFS(int v){
    queue<int> q;
    visited[v] = true;

    q.push(v);
    cout << v << " ";
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i = 1; i <= N; i++){
            if(!graph[tmp][i]) continue;

            if(!visited[i] && graph[i][tmp] == tmp){
                cout << i << " ";
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
    
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = b;
        graph[b][a] = a;
    }
    
    memset(visited, false, sizeof(visited));
    DFS(V);
    cout << '\n';
    // memset(visited, false, sizeof(visited));
    // BFS(V);
    // cout << '\n';
    memset(visited, false, sizeof(visited));
    BFS(V);
    
    return 0;
}