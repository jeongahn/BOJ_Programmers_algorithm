// # baekjoon 14716 silver1 현수막
// # 23년 상반기 Foscar 알고리즘 스터디 4조 4주차 4번
// # DFS

#include <iostream>
#define Max 251

using namespace std;

int N, M;
int Banner[Max][Max];
int visited[Max][Max] = {
    0,
};

int dir_x[] = {0,-1,-1,-1,0,1,1,1};
int dir_y[] = {-1,-1,0,1,1,1,0,-1};

void DFS(int y, int x)
{
    for(int i = 0; i < 8; i++){
        int new_y = y + dir_y[i];
        int new_x = x + dir_x[i];

        if(visited[new_y][new_x] == 0 && Banner[new_y][new_x] == 1 && new_y >=0 &&
        new_y < N && new_x >= 0 && new_x < M){
            visited[new_y][new_x] = 1;
            DFS(new_y, new_x);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Banner[i][j];
        }
    }

    int count = 0; // 글자 개수

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0 && Banner[i][j] == 1)
            {
                DFS(i, j);
                visited[i][j] = 1;
                count += 1;
            }
        }
    }

    cout << count << '\n';

    return 0;
}