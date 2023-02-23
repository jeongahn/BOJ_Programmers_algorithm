// # baekjoon 1389 silver1 케빈 베이컨의 6단계 법칙
// # 23년 상반기 Foscar 알고리즘 스터디 4조 4주차 1번
// # BFS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, A, B;
int sum = 999999999; // 정답값
int result = 0;

vector<int> v[101];
queue<int> q;
int kevin[101][101] = {
    0,
};
int visited[101];

void reset()
{
    for (int i = 0; i <= N; i++)
    {
        visited[i] = 0;
    }
}

void BFS(int a)
{
    reset();
    visited[a] = 1;

    q.push(a);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int i = 0; i < v[temp].size(); i++)
        {
            int idx = v[temp][i];
            if (visited[idx] == 0)
            {
                visited[idx] = 1;
                q.push(idx);
                kevin[a][idx] = kevin[a][temp] + 1;
                kevin[idx][a] = kevin[temp][a] + 1;
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for (int i = 1; i <= N; i++)
    {
        BFS(i);
    }

    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            tmp += kevin[i][j];
        }
        if (sum > tmp)
        {
            sum = tmp;
            result = i;
        }
    }
    cout << result << '\n';

    return 0;
}