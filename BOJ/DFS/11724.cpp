//baekjoon 11724 silver2 연결 요소의 개수 
//

#include <iostream>
#include <algorithm>
#define Max 1001
using namespace std;

bool arr[Max][Max];
bool visited[Max];

int n, m, u, v;

void dfs(int num){

    visited[num] = true;
    
    for(int i = 1; i <= n; i++){
        if(!visited[i] && arr[num][i]){
            dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i< m; i++){
        cin >> u >> v;
        
        arr[u][v] = true;
        //방향이 없기때문에 양방향 만들어주어야 한다
        arr[v][u] = true;
    }
    
    int cnt = 0;
    
    for(int i = 1; i<= n; i++){

        if(!visited[i]){
            cnt++;

            dfs(i);
        }
    }

    cout << cnt << '\n';

    return 0;
}