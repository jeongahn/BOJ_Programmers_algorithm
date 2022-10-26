//baekjoon 9019 gold4 DSLR
//BFS로 풀이
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int A,B;

bool visited[10000];

void BFS(){
    queue<pair<int, string>> q;
    q.push(make_pair(A, ""));
    visited[A] = true;

    while(!q.empty()){
        int tmp_num = q.front().first;
        string op_code = q.front().second;
        q.pop(); // pop을 해줘야 된다...
        
        if(tmp_num == B){
            cout << op_code << '\n';
            return;
        }

        int D,S,L,R;

        //D 연산
        D = (tmp_num * 2) % 10000;
        if(!visited[D]){
            visited[D] = true;
            q.push(make_pair(D, op_code + "D"));
        }

        //S 연산
        S = tmp_num - 1 < 0 ? 9999 : tmp_num - 1;
        if(!visited[S]){
            visited[S] = true;
            q.push(make_pair(S, op_code + "S"));
        }

        //L 연산
        L = (tmp_num % 1000) * 10 + (tmp_num / 1000);
        if(!visited[L]){
            visited[L] = true;
            q.push(make_pair(L, op_code + "L"));
        }

        //R 연산
        R = tmp_num / 10 + (tmp_num % 10) * 1000;
        if(!visited[R]){
            visited[R] = true;
            q.push(make_pair(R, op_code + "R"));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase;

    cin >> testCase;

    while(testCase--){
        cin >> A >> B;
        memset(visited, false, sizeof(visited)); // cstring 헤더파일에 있는 memset함수 활용해서 초기화
        BFS();
    }
    return 0;
}