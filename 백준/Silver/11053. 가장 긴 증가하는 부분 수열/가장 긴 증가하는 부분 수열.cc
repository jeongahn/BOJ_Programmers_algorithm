#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  int answer = 0;

  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1;
    for (int j = i - 1; j >= 1; j--)
    {
      if (arr[i] > arr[j])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    answer = max(dp[i], answer);
  }
  cout << answer << '\n';

  return 0;
}