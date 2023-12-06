#include <iostream>
using namespace std;

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;

  int i = 1;
  while (x > i)
  {
    x -= i;
    i++;
  }
  if (i % 2 == 0)
  {
    cout << x << '/' << i - x + 1;
  }
  else
  {
    cout << i - x + 1 << '/' << x;
  }
  cout << '\n';
  return 0;
}