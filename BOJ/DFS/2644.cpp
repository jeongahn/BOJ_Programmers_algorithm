//baekjoon 2644 silver2 촌수계산

#include <iostream>
#include <algorithm>
#include <vector>
#define Max 101
using namespace std;

int n; // 사람의 수
int first, second; //촌수를 계산해야 하는 다른 두 사람
int m; // 관계의 개수
vector<int> v[Max]; // 그래프
int visited[Max];
int cnt = 0;
int result = -1; // default값 -1 이어야 한다. 문제에서 제시됨

void dfs(int f, int cnt){ // 재귀를 돌면서 모든 경우마다 cnt가 증가하지 않게 하기 위해서 인자로 주어야함
    visited[f] = 1;
    if(f == second){
        result = cnt;
    }
    
    for(int i = 0; i < v[f].size(); i++){
        int idx = v[f][i];
        if(visited[idx] == 0){
            dfs(idx, cnt+1); // 여기서 처럼 각 부모에 해당하는 자식은 1촌만 증가할 수 있도록
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    cin >> first >> second;
    cin >> m;

    int x,y;
     
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        //making graph.
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(first, 0);
    
    cout << result << '\n';

    return 0;
    
}