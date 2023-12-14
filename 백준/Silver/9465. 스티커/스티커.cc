#include <iostream>
using namespace std;

int btn[2][100001];
int dp[2][100001];

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int testCase;

  cin >> testCase;

  while (testCase--)
  {
    int n;
    cin >> n;

    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> btn[i][j];
      }
    }

    dp[0][0] = btn[0][0];
    dp[1][0] = btn[1][0];
    dp[0][1] = btn[0][1] + dp[1][0];
    dp[1][1] = btn[1][1] + dp[0][0];

    for (int i = 2; i < n; i++)
    {
      dp[0][i] = btn[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
      dp[1][i] = btn[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
  }

  return 0;
}