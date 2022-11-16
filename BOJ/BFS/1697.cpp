//baekjoon 1697 silver1 숨바꼭질 
// 

#include <iostream>
#include <algorithm>
#include <queue>
#define Max 100001

using namespace std;

int n,k;

bool visited[Max];
int dist[Max];



void BFS(int tmp){
    queue<int> q;
    q.push(tmp);
    visited[tmp] = true;
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        

        if(tmp == k){
            cout << dist[tmp] << '\n';
            break;
        }else{

            if(tmp > 0){ // 이 조건을 밑의 조건과 and 연산으로 묶을 경우 outofBounds error 발생...
            // 주의하자
                if(!visited[tmp-1]){
                    visited[tmp-1] = true;
                    dist[tmp - 1] = dist[tmp] + 1;
                    q.push(tmp-1);
                }    
            }
            if(!visited[tmp+1] && tmp <= k){
                visited[tmp+1] = true;
                dist[tmp+1] = dist[tmp] + 1;
                q.push(tmp+1);
            }
            if(tmp > 0 && tmp <= 50000){
                if(!visited[tmp*2]){
                    visited[tmp*2] = true;
                    dist[tmp*2] = dist[tmp] + 1;
                    q.push(tmp*2);
                }    
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    

    if(k <= n){ // 수빈이 보다 동생이 더 앞에 위치할경우 순간이동이나 앞으로 이동할 필요가 없다.
        cout << n - k << '\n';
        return 0;
    }
    
    BFS(n);
    
    return 0;
}