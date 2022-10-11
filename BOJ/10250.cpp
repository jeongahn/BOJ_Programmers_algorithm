//baekjoon 10250 bronze2 ACM 호텔

#include <iostream>

using namespace std;

int ACM[100][100];

int main(){
    int T, H, W, N;

    cin >> T;

    for(int i = 0; i < T; i++){

        cin >> H >> W >> N;

        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                ACM[i][j] = i * 100 + j;
            }
        }


        int tmp = N;
        
        for(int j = 1; j <= W; j++){
            for(int i = 1; i <= H; i++){
                --tmp;
                if(tmp == 0){
                    cout << ACM[i][j] << '\n';
                    break;
                }
            }
        }
        
    }

    return 0;
}