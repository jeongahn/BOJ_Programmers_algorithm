//baekjoon 1987 gold4 알파벳
// 풀이 : 백트래킹 문제, 
// 만약에 
// c a b d f
// a c b d e 이처럼 배열이 나열되어 있다고 했을때
// 먼저 아래 a를 방문했을때 그다음 방문할 수 있는 경로가 없다
// 하지만 c기준 오른쪽 a를 방문하게 되면 b d f e 이처럼 다른 최대 경로를 탐색할 수 있다.
// 따라서 방문을 하고 다시는 못 밟는 곳이 아니라 다른 경로로 갈테니 나중에 다시 밟을 수 있다면
// 밟아도 된다는 방식으로 구현이 되어야 함
// 그리고 지속적으로 최대 경로 길이를 update 해주기 위해 max함수를 통해 최댓값을 갱신한다


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define Max 21
using namespace std;

int R, C;
// int recurr_cnt;
int result;

int alphabet[Max][Max];
int visited[Max][Max];
int checking[27]; // 알파벳 26자리

//top, left, bottom, right
int dir_y[4] = {-1,0,1,0};
int dir_x[4] = {0,-1,0,1};

void dfs(int y, int x, int cnt){
    // cout << int(alphabet[y][x] - 64) << '\n';

    result = max(result, cnt);
    
    for(int i = 0; i < 4; i++){
        int next_y = y + dir_y[i];
        int next_x = x + dir_x[i];

        
        if(next_y < 0 || next_y >= R || next_x < 0 || next_x >= C){
            continue;
        }
        if(checking[int(alphabet[next_y][next_x]) - 64] == 0){ // 이런 경우에는 굳이 이렇게 64가 아니라 - 'A' 가 더 좋음 내가 몰랐던것...;
            checking[int(alphabet[next_y][next_x]) - 64] = 1;
            dfs(next_y, next_x, cnt + 1); // 
            checking[int(alphabet[next_y][next_x]) - 64] = 0; // 다시 탐색이 가능하도록 초기화
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> R >> C;

    string s;
    
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            alphabet[i][j] = s[j];
        }
    }
    checking[int(alphabet[0][0]) - 64] = 1;
    dfs(0, 0, 1);

    cout << result << '\n';

    return 0;
    
}