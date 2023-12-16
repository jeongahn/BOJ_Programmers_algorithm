#include <iostream>
#include <queue>
#include <climits>
#include <cmath>

#define MAX_N 100001

using namespace std;

int visited[MAX_N];

int dijkstra(int root_n, int desti)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  if (root_n > desti)
  {
    return abs(desti - root_n);
  }

  pq.push({0, root_n});

  while (!pq.empty())
  {
    int curr_time = pq.top().first;
    int x = pq.top().second;

    pq.pop();
    if (x == desti)
    {
      return curr_time;
    }

    if (x * 2 < MAX_N && !visited[x * 2])
    {
      pq.push({curr_time, x * 2});
      visited[x * 2] = 1;
    }
    if (x + 1 < MAX_N && !visited[x + 1])
    {
      pq.push({curr_time + 1, x + 1});
      visited[x + 1] = 1;
    }
    if (x - 1 >= 0 && !visited[x - 1])
    {
      pq.push({curr_time + 1, x - 1});
      visited[x - 1] = 1;
    }
  }
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n, k;

  cin >> n >> k;

  cout << dijkstra(n, k) << '\n';
  return 0;
}