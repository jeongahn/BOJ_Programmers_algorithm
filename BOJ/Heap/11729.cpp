//baekjoon 11729 silver2 최대 힙 
//priority queue는 가장 큰 값이 우선순위인게 default 즉 heap에서는 max heap과 같다
//greater를 쓴다면 min heap이겠지..?

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    priority_queue<int> pq;
    
    cin >> n;

    for(int i = 0; i< n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty()){ //힙이 비어 있다면 0 출력 아니면 가장 큰값 출력 및 제거
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{ // 자연수라면 heap에 추가
            pq.push(tmp);
        }
    }

    return 0;
}