#include <iostream>
#include <queue>
using namespace std;
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  priority_queue<int> pq;

  int d;
  cin >> d;

  for (int i = 1; i < n; i++)
  {
    int other;
    cin >> other;
    pq.push(other);
  }
  int cnt = 0;
  while (!pq.empty())
  {
    int top = pq.top();
    pq.pop();
    if (d <= top)
    {
      top--;
      d++;
      cnt++;
      pq.push(top);
    }
  }
  cout << cnt << '\n';
  return 0;
}