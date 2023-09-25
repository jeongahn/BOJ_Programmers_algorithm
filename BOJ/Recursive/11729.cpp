#include <iostream>

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

  int result = (1 << n) - 1;
  cout << result << '\n';
  hanoi(n, 1, 2, 3);

  return 0;
}