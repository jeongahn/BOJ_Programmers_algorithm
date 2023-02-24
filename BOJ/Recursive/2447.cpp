// baekjoon 2447 gold5 별 찍기 - 10
// 23년 상반기 Foscar 알고리즘 스터디 5조 3주차 4번
// Recursive, 분할 정복

#include <iostream>
#define Max 6666
using namespace std;

int n;
char board[Max][Max];

void star(int i, int j, int n)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
    {
        cout << " ";
    }
    else if (n / 3 == 0)
    {
        cout << "*";
    }
    else
    {
        star(i, j, n / 3);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            star(i, j, n);
        }
        cout << '\n';
    }

    return 0;
}
