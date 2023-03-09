// baekjoon 6064 silver1 카잉 달력

#include <iostream>

using namespace std;

int m, n, x, y;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }

    return a;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> m >> n >> x >> y;
        int gcd = GCD(m, n);

        int min_gcd = (m * n) / gcd;
        int result = -1;

        for (int j = x; j <= min_gcd; j+=m)
        {
            int ny = j%n;
            if(ny == 0){
                ny = n;
            }
            if(ny == y){
                result = j;
                break;
            }
            
        }
        cout << result << '\n';
    }
    return 0;
}