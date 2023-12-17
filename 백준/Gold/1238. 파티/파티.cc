#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> graph[1001];
int dist[10001];

int dijkstra(int start, int n, int desti)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(dist, dist + n + 1, INT_MAX);

  dist[start] = 0;

  pq.push({0, start});

  while (!pq.empty())
  {
    int curr_dist = pq.top().first;
    int curr_node = pq.top().second;
    pq.pop();

    if (curr_dist > dist[curr_node])
    {
      continue;
    }
    for (auto edge : graph[curr_node])
    {
      int next_node = edge.first;
      int weight = edge.second;

      if (dist[next_node] > curr_dist + weight)
      {
        dist[next_node] = curr_dist + weight;
        pq.push({dist[next_node], next_node});
      }
    }
  }
  return dist[desti];
}

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n, m, x;

  cin >> n >> m >> x;

  while (m--)
  {
    int u, v, t;
    cin >> u >> v >> t;

    graph[u].push_back({v, t});
  }

  int d_to_s[n + 1];
  for (int i = 1; i <= n; i++)
  {
    d_to_s[i] = dijkstra(x, n, i);
  }

  int s_to_d[n + 1];
  for (int i = 1; i <= n; i++)
  {
    s_to_d[i] = dijkstra(i, n, x);
  }
  int max_totaltime = 0;

  for (int i = 1; i <= n; i++)
  {
    if (max_totaltime < (d_to_s[i] + s_to_d[i]))
    {
      max_totaltime = d_to_s[i] + s_to_d[i];
    }
  }
  cout << max_totaltime << '\n';

  return 0;
}