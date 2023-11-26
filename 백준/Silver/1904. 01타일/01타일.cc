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
  if (n <= 2)
  {
    cout << n << '\n';
  }
  else
  {
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < n; i++)
    {
      arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }
    cout << arr[n - 1] << '\n';
  }

  return 0;
}