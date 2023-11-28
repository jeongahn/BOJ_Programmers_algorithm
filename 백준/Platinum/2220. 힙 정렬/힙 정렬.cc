#include <iostream>
using namespace std;

int arr[100001];

void swap(int a, int b)
{
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;

  cin >> n;

  arr[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    arr[i] = i;
    swap(i, i - 1);

    for (int j = i - 1; j > 1; j /= 2)
    {
      swap(j, j / 2);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << '\n';

  return 0;
}