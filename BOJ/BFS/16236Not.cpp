//baekjoon 16236 gold3 아기 상어
//
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

#define max 21

int space[max][max];
int dir_x[4] = {-1,0,1,0};
int dir_y[4] = {0,-1,0,1};
int result = 0;
int N;
int dist[max][max];


struct baby_shark{
    int y;
    int x;
    int size;
    int ate;
};




bool find_check(baby_shark& s){
    queue<pair<int, int>> q;

    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            dist[i][j] = -1;
        }
    }
    q.push(make_pair(s.y, s.x));

    dist[s.y][s.x] = 0;

    //BFS

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    baby_shark s;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> space[i][j];
            if(space[i][j] == 0){
                s.y = i;
                s.x = j;
                s.size = 2;
                s.ate = 0;
            }
        }
    }
    while(true){
        
    }
    
    return 0;
}