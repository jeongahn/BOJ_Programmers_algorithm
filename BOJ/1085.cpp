//baekjoon 1085 bronze3 직사각형에서 탈출

#include <iostream>

using namespace std;

int main(){
    int x,y,w,h;

    cin >> x >> y >> w >> h;
    
    int resultX;
    int resultY;
    int final_result;

    resultX = min(w-x, x - 0);
    resultY = min(h-y, y - 0);

    final_result = min(resultX, resultY);

    cout << final_result << '\n';

    return 0;
}