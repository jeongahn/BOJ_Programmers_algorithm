// # baekjoon 2210 silver2 숫자판 점프
// # 23년 상반기 Foscar 알고리즘 스터디 3조 4주차 3번
// # DFS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int number_board[5][5];
vector<int> enable;

int answer;
int dir_y[] = {0,1,0,-1};
int dir_x[] = {1,0,-1,0};

void DFS(int a, int b, int num, int cnt){
    if(cnt == 6){
        enable.push_back(num);
        return;
    }

    for(int i = 0; i < 4; i++){
        int new_y = a + dir_y[i];
        int new_x = b + dir_x[i];

        if(new_y > 4 || new_y < 0 || new_x > 4 || new_x < 0){
            continue;
        }
        
        DFS(new_y, new_x, num * 10 + number_board[new_y][new_x], cnt + 1);
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> number_board[i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            DFS(i, j, 0, 0);
        }
    }

    sort(enable.begin(), enable.end());
    auto last = std::unique(enable.begin(), enable.end());
    enable.erase(last, enable.end());

    cout << enable.size() << '\n';

    return 0;
}