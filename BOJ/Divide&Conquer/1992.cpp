//baekjoon 1992 silver1 쿼드트리 
// 

#include <iostream>
#include <algorithm>
#include <string>
#define max 65
using namespace std;

int video_arr[max][max];
int n;
string result = "";

void quad_T(int y, int x, int size){
    
    bool white = false;
    bool black = false;

    if(video_arr[y][x] == 1){
        white = true;
    }else{
        black = true;
    }

    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(video_arr[i][j] == 1){
                white = true;
            }else{
                black = true;
            }
            if(white && black){
                result += "(";
                quad_T(y, x, size / 2);
                quad_T(y, x + size / 2, size / 2);
                quad_T(y + size / 2, x, size / 2);
                quad_T(y + size / 2, x + size / 2, size / 2);
                result += ")";
                return; // void함수의 종료
            }
        }
    }
    if(white == true){
        result += '1';
    }else{
        result += '0';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++){
            video_arr[i][j] = tmp[j] - '0';
        }
    }

    
    quad_T(0, 0, n);
    
    cout << result << '\n';
    
    return 0;
}