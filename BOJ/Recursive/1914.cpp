#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void hanoi(int n, int a, int b, int c)
{
  if (n == 1)
    cout << a << ' ' << c << '\n';
  else
  {
    hanoi(n - 1, a, c, b);         // 1번(a) -> 2번(b)로 옮기는 과정
    cout << a << ' ' << c << '\n'; // 2번(b) -> 3번(c)로 옮기는 과정
    hanoi(n - 1, b, a, c);
  }
}

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;

  cin >> n;

  string a = to_string(pow(2, n));
  int idx = a.find('.');
  a = a.substr(0, idx);
  a[a.length() - 1] -= 1;
  cout << a << '\n';

  if (n <= 20)
  {
    hanoi(n, 1, 2, 3);
  }

  return 0;
}