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
        priority_queue<int> pq; // 가장 우선순위 값이 높은것 부터 출력 되기 때문에 비교 하기 위한 pq
        
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
            }else{// 가장 앞에 오는 값이 그 순서의 중요도의 값과 같다면 출력, 순서를 매기기 위해 counting
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