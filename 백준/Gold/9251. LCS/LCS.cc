#include <iostream>
#include <string>
#define MAX_N 1001
using namespace std;

int table[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  string s1, s2;

  cin >> s1 >> s2;

  for (int i = 0; i <= s1.length(); i++)
  {
    for (int j = 0; j <= s2.length(); j++)
    {
      if (i == 0 || j == 0)
      {
        table[i][j] = 0;
      }
      else if (s1[i - 1] == s2[j - 1])
      {
        table[i][j] = table[i - 1][j - 1] + 1;
      }
      else
      {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      }
    }
  }

  cout << table[s1.length()][s2.length()] << '\n';
  return 0;
}