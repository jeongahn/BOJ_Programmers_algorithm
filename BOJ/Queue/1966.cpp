//baekjoon 1966 silver3 프린터 큐

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int testCase;

    cin >> testCase;

    int N, M, priority;

    for(int i = 0; i < testCase; i++){
        cin >> N >> M;
        // int max = 0; 
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        
        for(int j = 0; j < N; j++){
            cin >> priority;
            
            pq.push(priority);
                
            q.push(pair<int, int>(j, priority));
        }
        int cnt = 0;
        
        while(!q.empty()){
            // cout << max << '\n';
            int idx = q.front().first;
            int value = q.front().second;
            
            if(pq.top() > value){
                q.push(q.front());
                q.pop();
            }else{
                q.pop();
                pq.pop();
                cnt++;

                if(idx == M){
                    cout << cnt << '\n';
                    break;
                }
            }
        }  
    }  
    return 0;
}