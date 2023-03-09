// baekjoon 11286 silver1 절댓값 힙

#include <iostream>
#include <queue>
#define Max 100001

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(make_pair(abs(x), x));
        }
    }

    return 0;
}