//baekjoon 1927 silver2 최소 힙 
//priority queue

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    int x;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << '\n';
                continue;
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(x);
        }
    }
    

    return 0;
}