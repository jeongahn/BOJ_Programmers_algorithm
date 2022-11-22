//baekjoon 1541 silver2 잃어버린 괄호  
//분할정복

#include <iostream>
#include <algorithm>
#define Max 2188

using namespace std;

int paper[Max][Max];
int result[3]; // -1, 0, 1 값을 counting할 배열

void divide(int y, int x, int size){

    for(int i = y; i < y+ size; i++){
        for(int j = x; j< x + size; j++){
            if(paper[i][j] != paper[y][x]){
                int tmp = size/3;
                //// 9등분시 첫번째 줄
                divide(y, x, tmp);
                divide(y, x + tmp, tmp);
                divide(y, x + 2*tmp, tmp);
                //// 두번째 줄
                divide(y + tmp, x, tmp);
                divide(y + tmp, x + tmp, tmp);
                divide(y + tmp, x + 2*tmp, tmp);
                //// 세번째 줄
                divide(y + 2*tmp, x, tmp);
                divide(y + 2*tmp, x + tmp, tmp);
                divide(y + 2*tmp, x + 2*tmp, tmp);

                return; // void함수의 종료 - 반복문 종료   
            }
        }
    }
    
    result[paper[y][x] + 1]++; // -1은 0에, 0은 1에, 1은 2에

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> paper[i][j];
        }
    }

    divide(1,1,n);

    for(int i = 0; i < 3; i++) cout << result[i] << '\n';
    return 0;
    
}