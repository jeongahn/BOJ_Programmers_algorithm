#include <iostream>
#include <queue>
#include <climits>
#define MAX_N 20001

using namespace std;

vector<pair<int, int>> graph[MAX_N];
int dist[MAX_N];
int parent[MAX_N];

void dijkstra(int root_n, int cnt_n)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(dist, dist + cnt_n + 1, INT_MAX);
  fill(parent, parent + cnt_n + 1, -1);

  dist[root_n] = 0;
  pq.push({0, root_n});

  while (!pq.empty())
  {
    int curr_dist = pq.top().first;
    int curr_node = pq.top().second;

    pq.pop();

    if (curr_dist > dist[curr_node])
    {
      continue;
    }

    for (auto i : graph[curr_node])
    {
      int next_node = i.first;
      int weight = i.second;

      if (dist[next_node] > curr_dist + weight)
      {
        dist[next_node] = curr_dist + weight;
        parent[next_node] = curr_node;
        pq.push({dist[next_node], next_node});
      }
    }
  }

  for (int i = 1; i <= cnt_n; i++)
  {
    if (dist[i] == INT_MAX)
    {
      cout << "INF" << '\n';
      continue;
    }
    cout << dist[i] << '\n';
  }
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int v, e;

  cin >> v >> e;

  int root_n;

  cin >> root_n;

  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back({v, w});
  }
  dijkstra(root_n, v);
  return 0;
}