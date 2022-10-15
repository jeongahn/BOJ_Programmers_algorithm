//baekjoon 11866 silver 5 요세푸스 문제 0

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K;

    cin >> N >> K;

    queue<int> yps;

    for(int i = 1; i <= N; i++){
        yps.push(i);
    }
    
    int count = 1;
    cout << "<";
    while(!yps.empty()){
        if(count % K == 0){
            int a = yps.front();
            yps.pop();
            if(yps.empty()) {
                cout << a << ">";
            }
            else{
                cout << a << ", ";
            }
        }else{
            int tmp = yps.front();
            yps.pop();
            yps.push(tmp);
        }    
        count++;
    }

    return 0;
    
}