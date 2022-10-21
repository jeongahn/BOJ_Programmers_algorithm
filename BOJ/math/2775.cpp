//baekjoon 2775 bronze1 부녀회장이 될테야

#include <iostream>


using namespace std;

int arr[15][14] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14},};


int number(int floor, int roomNum){
    int sum = 0;
    for(int i = 0; i <= roomNum; i++){
        sum += arr[floor-1][i];
    }

    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    
    int N, K;

    for(int i = 1; i <= 14; i++){
        for(int j = 0; j < 14; j++){
            arr[i][j] = number(i, j);
            //cout << arr[i][j] << " "; //echo checking
        }
        //cout << '\n'; //echo checking
    }

    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> K >> N;

        cout << arr[K][N-1] << '\n';
    }

    return 0;
}