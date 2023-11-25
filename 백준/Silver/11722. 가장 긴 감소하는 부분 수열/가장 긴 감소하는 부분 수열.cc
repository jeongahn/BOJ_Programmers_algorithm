#include <iostream>
using namespace std;
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int arr[n];
  int dp[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  dp[0] = 1;

  for (int i = 1; i < n; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (arr[i] < arr[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
  }

  int max = 0;

  for (int i = 0; i < n; i++)
    if (max < dp[i])
      max = dp[i];

  cout << max << '\n';
  
  return 0;
}