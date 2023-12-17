#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 100001

using namespace std;

int point, result;
int visited[MAX_N];
vector<pair<int, int>> graph[MAX_N];

void DFS(int start, int dist)
{
  if (visited[start])
  {
    return;
  }
  visited[start] = 1;

  if (result < dist)
  {
    result = dist;
    point = start;
  }
  for (auto edge : graph[start])
  {
    int next_node = edge.first;
    int weight = edge.second;
    if (!visited[next_node])
    {
      DFS(next_node, dist + weight);
    }
  }
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int v;

  cin >> v;

  while (v--)
  {
    int start;

    cin >> start;

    int cnt = 0;
    int tmp_node = -1;
    while (true)
    {
      int a;
      cin >> a;
      if (a == -1)
      {
        break;
      }
      if (cnt % 2 == 0)
      {
        tmp_node = a;
        cnt++;
        continue;
      }
      if (cnt % 2 == 1)
      {
        graph[start].push_back({tmp_node, a});
        cnt++;
      }
    }
  }
  DFS(1, 0);
  memset(visited, 0, sizeof(visited));
  result = 0;

  DFS(point, 0);
  cout << result << '\n';
  return 0;
}