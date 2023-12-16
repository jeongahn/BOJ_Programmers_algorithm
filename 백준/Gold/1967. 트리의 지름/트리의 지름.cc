#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define MAX_N 10001

using namespace std;

int visited[MAX_N];
int result;
int tmp_point;
vector<pair<int, int>> graph[MAX_N];
void DFS(int start, int len)
{
  if (visited[start])
    return;
  visited[start] = 1;

  if (len > result)
  {
    result = len;
    tmp_point = start;
  }
  for (auto edge : graph[start])
  {
    DFS(edge.first, len + edge.second);
  }
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;

  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  DFS(1, 0);
  result = 0;
  memset(visited, 0, sizeof(visited));

  DFS(tmp_point, 0);

  cout << result << '\n';

  return 0;
}