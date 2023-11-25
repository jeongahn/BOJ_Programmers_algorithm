#include <iostream>
using namespace std;
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int t[n + 1], p[n + 1], dp[n + 2];
  for (int i = 1; i <= n; i++)
    cin >> t[i] >> p[i];
  dp[n + 1] = 0;
  for (int i = n; i >= 1; i--)
  {
    if (i + t[i] > n + 1)
      dp[i] = dp[i + 1];
    else
      dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
  }
  cout << dp[1] << '\n';

  return 0;
}