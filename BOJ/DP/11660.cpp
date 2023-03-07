// baekjoon 11660 silver1 구간 합 구하기 5

#include <iostream>
#define Max 1025

using namespace std;

int n, m;
int matrix[Max][Max];
int stacking_sum[Max][Max];
int visitied[Max][Max];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cin >> matrix[i][j];
            stacking_sum[i][j] = matrix[i][j];
        }
    }
    // for(int i = 1; i < n+1; i++){
    //     for(int j = 1; j < n+1; j++){
    //         cout << matrix[i][j];
    //     }
    //     cout << '\n';
    // }

    // 누적합으로 만들기
    for(int i = 2; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            stacking_sum[i][j] += stacking_sum[i-1][j];
        }
    }
    // for(int i = 1; i < n+1; i++){
    //     for(int j = 1; j < n+1; j++){
    //         cout << stacking_sum[i][j];
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < m; i++){
        int x1, x2, y1, y2;
        int total = 0;

        cin >> y1 >> x1 >> y2 >> x2;

        for(int x = x1; x <= x2; x++){
            total += (stacking_sum[y2][x] - stacking_sum[y1][x] + matrix[y1][x]);     
        }

        cout << total << '\n';
    }

    return 0;
}