// # baekjoon 7562 silver1 나이트의 이동
// # 23년 상반기 Foscar 알고리즘 스터디 3조 4주차 4번
// # BFS

#include <iostream>
#include <queue>
#define Max 301
using namespace std;

int dir_x[] = {1,2,2,1,-1,-2,-2,-1};
int dir_y[] = {2,1,-1,-2,-2,-1,1,2};

queue<pair<int, int>> q;

int chess[Max][Max] = {0,};
int arr[Max][Max] = {0,};
int visited[Max][Max] = {0,};

int test_Case;
int curr_x, curr_y;
int target_x, target_y;
int length;

void reset(){
    
	while (!q.empty()) q.pop();
	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < Max; j++) {
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
}

void BFS(int y, int x){
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;

        q.pop();

        if(a == target_y && b == target_x){
            cout << arr[a][b] << '\n';
            while(!q.empty()) {
                q.pop();
            }
            break;
        }

        for(int i = 0; i < 8; i++){
            int new_y = a + dir_y[i];
            int new_x = b + dir_x[i];

            if(0<=new_y && 0<=new_x && new_y <length && new_x < length && !visited[new_y][new_x]) {
                q.push({new_y,new_x});
                visited[new_y][new_x]=true;
                arr[new_y][new_x]=arr[a][b]+1;
            }
        }
    }
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> test_Case;

    for(int i = 0; i < test_Case; i++){
        cin >> length;
        cin >> curr_y >> curr_x;
        cin >> target_y >> target_x;

        BFS(curr_y, curr_x);
        reset();
    }




    return 0;
}