//baekjoon 1149 silver1 RGB거리  
// 여기서 가장 중요한 포인트는 현재 색깔을 칠할때 이전 색깔은 현재색깔이 아닌 다른 색을 칠했다는것
// 현재 색을 칠할때 이전에 칠하지 않았던 색들중 그 색까지 칠하기 까지의 누적 cost의 값들을 비교해
// 최소값을 현재 칠하는 색의 cost값에 더해준다.
// 이렇게 되면 각각의 색마다 칠할때 cost 누적값들이 생기고 다를텐데, 결국 n개의 개수만큼 칠했을때
// 최솟값을 구해야 하므로, min함수를 argument를 3개 받는 함수로 overloading하여 return해준다

#include <iostream>


using namespace std;

int curr_cost[1001][4]; //최대 n개의 개수만큼 R,G,B 3개의 색중 한개 색칠 가능
int stack_cost[1001][4]; // 누적비용


int min(int a, int b){
    return a < b ? a : b;
}

// overloading

int min(int a, int b, int c){
    int temp = min(a, b);
    return min(temp, c);
}

int dp(int n){

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 3; j++){

            if(j == 1){
                stack_cost[i][1] = curr_cost[i][1] + min(stack_cost[i-1][2], stack_cost[i-1][3]);
            }else if(j == 2){
                stack_cost[i][2] = curr_cost[i][2] + min(stack_cost[i-1][1], stack_cost[i-1][3]);
            }else if(j == 3){
                stack_cost[i][3] = curr_cost[i][3] + min(stack_cost[i-1][1], stack_cost[i-1][2]);
            }
        }
    }

    return min(stack_cost[n][1], stack_cost[n][2], stack_cost[n][3]);
    
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;

    int cost;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j ++){
            cin >> cost;
            curr_cost[i][j] = cost;
        }
    }    

    stack_cost[1][1] = curr_cost[1][1];
    stack_cost[1][2] = curr_cost[1][2];
    stack_cost[1][3] = curr_cost[1][3]; // 제일 처음은 누적 cost가 자기 자신이기 때문에
    
    
    int min_cost = dp(n);

    cout << min_cost << '\n';

    return 0;
    
}