#include <iostream>
using namespace std;

int table[501][501];
int dp[501][501];

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cin >> table[i][j];
    }
  }
  dp[0][0] = table[0][0];
  if (n == 1)
  {
    cout << table[0][0] << '\n';
    return 0;
  }
  else
  {
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        if (j == 0)
        {
          dp[i][j] = dp[i - 1][j] + table[i][j];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j - 1] + table[i][j], dp[i - 1][j] + table[i][j]);
        }
      }
    }
  }
  int max_num = 0;

  for (int i = 0; i < n; i++)
  {
    if (max_num < dp[n - 1][i])
      max_num = dp[n - 1][i];
  }
  cout << max_num << '\n';
  return 0;
}