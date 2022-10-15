//baekjoon 1018 silver4 체스판 다시 칠하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board[51][51];



int counting(int a, int b){
    int WB_count = 0;
    int BW_count = 0;
    int cnt_row = 0;

    
    // WBWB 순서 경우
    for(int i = a; i < a+8; i++){
        cnt_row++;
        int cnt = 1;
        for(int j = b; j < b + 8; j++){

            //홀수 번째 행 칸이 BWBW 순서여야 해서
            if(cnt_row % 2 == 1){
                if(cnt % 2 == 1 && board[i][j] == 'B'){
                    WB_count++;
                }else if(cnt % 2 == 0 && board[i][j] == 'W'){
                    WB_count++;
                }
            }else{
                if(cnt % 2 == 1 && board[i][j] == 'W'){
                    WB_count++;
                }else if(cnt % 2 == 0 && board[i][j] == 'B'){
                    WB_count++;
                }
            }
            cnt++;
        }
    }
    // BWBW 순서 경우
    cnt_row = 0;
    
    for(int i = a; i < a+8; i++){
        cnt_row++;
        int cnt = 1;
        for(int j = b; j < b + 8; j++){

            //홀수 번째 행 칸이 WBWB 순서여야 해서
            if(cnt_row % 2 == 1){
                if(cnt % 2 == 1 && board[i][j] == 'W'){
                    BW_count++;
                }else if(cnt % 2 == 0 && board[i][j] == 'B'){
                    BW_count++;
                }
            }else{
                if(cnt % 2 == 1 && board[i][j] == 'B'){
                    BW_count++;
                }else if(cnt % 2 == 0 && board[i][j] == 'W'){
                    BW_count++;
                }
            }
            cnt++;
        }
    }
    

    return min(WB_count, BW_count);
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector <int> pre_result;

    int N, M;
    cin >> N >> M;
    
    char a;
    int count = 0;
    int result;
    
    // 입력된 값으로 만든 체스판
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a;
            board[i][j] = a;
        }
    }
    //다시 색칠해야 하는 시작점 좌표
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            count = counting(i, j);
            pre_result.push_back(count);
        }
    }

    result = *min_element(pre_result.begin(), pre_result.end());

    cout << result << '\n';

    return 0;
}