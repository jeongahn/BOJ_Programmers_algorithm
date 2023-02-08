// baekjoon 10994 silver4 별 찍기-19
// 23년 상반기 Foscar 알고리즘 스터디 3조 3주차 3번
// 재귀

#include <iostream>
#define Max 400
using namespace std;


char star[Max][Max];




void draw(int a, int b, int cnt){
    for(int i = 0; i < cnt; i++){
        if(i == 0 || i == cnt - 1){
            for(int j = 0; j < cnt; j++){
                star[a+i][b+j] = '*';
            }
        }else{
            star[a+i][b] = '*';
            star[a+i][b+cnt-1] = '*';
        }
    }
}
void recursive(int a, int b, int n){
    
    int cnt = 1 + (n-1) * 4;
    draw(a, b, cnt);

    if (n == 1){
        return;
    }    

    recursive(a + 2, b + 2, n-1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    int cnt = 1;

    cnt += (n-1) * 4;

    // 공백 채워주기
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt; j++){
            star[i][j] = ' ';
        }
    }

    
    recursive(0, 0, n);
    //별 출력
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt; j++){
            cout << star[i][j];
        }
        cout << '\n';
    }
    
    
    return 0;
}
