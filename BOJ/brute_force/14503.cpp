// baekjoon 14503 gold5 로봇 청소기
// 23년 상반기 Foscar 알고리즘 스터디 5조 1주차 3번

#include <iostream>

#define Max 51

using namespace std;

int n, m; // 3 <= n,m <= 50
int r,c,d; // d - 0 : 북쪽, 1 - 동쪽, 2 : 남쪽, 3 : 서쪽
int room[Max][Max];
int total; // 청소기가 총 청소하는 칸의 개수
int visited[Max][Max] = {0,}; // 방문을 했는지 안했는지 체크

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; // 북, 동, 남, 서 기준으로 왼쪽방향으로 이동이므로 이렇게 방향 설정


void DFS(){
    for(int i = 0; i < 4; i++){ // 네 방향 청소, 계속 왼쪽으로 회전
        int next_d = (d + 3 - i) % 4; // 2-2에서 계속 continue되서 돌아오게 되면 d 기준으로 계속 왼쪽으로 방향전환 필요
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];


        if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m || room[next_r][next_c] == 1){
            continue;
        } // 2-2. 왼쪽 방향에 청소할 공간이 없다면 그 방향으로 회전하고 2번으로 돌아간다.


        if(room[next_r][next_c] == 0 && visited[next_r][next_c] == 0){
            
            r = next_r;
            c = next_c;
            d = next_d;
            total++; // 1번이 현재 위치를 청소하는 거라서
            visited[next_r][next_c] = 1;
            DFS();
        } // 2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 있다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행

    }

    int back_idx = d > 1 ? d - 2 : d + 2;
    int back_r = r + dx[back_idx];
    int back_c = c + dy[back_idx];

    // 2-3. 일단 이 조건문에 왔다는 거부터 네 방향 모두 청소가 이미 되어있거나 벽인 경우
    if(back_r >= 0 && back_r <= n && back_c >= 0 && back_c <= m){
        
        // 뒤 방향으로 후진이 가능한 경우 2번으로 돌아간다.
        if(room[back_r][back_c] == 0){
            r = back_r;
            c = back_c;
            DFS();
        }else{
            cout << total << '\n';
            exit(0);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    cin >> r >> c >> d;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
        }
    }

    //1번 현재 위치를 청소한다.
    total++;
    visited[r][c] = 1;
    
    DFS();


    return 0;


}