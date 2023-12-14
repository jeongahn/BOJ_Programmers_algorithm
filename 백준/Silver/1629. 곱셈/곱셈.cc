#include <iostream>
using namespace std;

long long FastPow(long long a, long long b, long long c)
{
  if (b == 0)
  {
    return 1;
  }
  if (b == 1)
  {
    return a % c;
  }

  if (b % 2 != 0)
  {
    b = FastPow(a, (b - 1) / 2, c);
    return a * b % c * b % c;
  }
  else
  {
    b = FastPow(a, b / 2, c);
    return (b * b) % c;
  }
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  long long a, b, c;

  cin >> a >> b >> c;

  cout << FastPow(a, b, c) % c << '\n';

  return 0;
}
