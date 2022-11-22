//baekjoon 11659 silver3 구간 합 구하기 4  

#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;
    int arr[n];

    arr[0] = 0;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 입력값 5 4 3 2 1
    // 이 경우에 누적 합을 2중 for문을 사용하지 않고 구하려면
    // 말그대로 누적 합을 새로운 배열에 담아서 범위 값이 마지막에 주어졌을때 빼면 된다
    // 입력은 5 4 3 2 1로 들어왔지만
    // 제일 처음 시작 값은 default로 원래 입력값중 처음값을 누적합으로 더하지 않는다
    // 위 예시에서의 누적합을 담은 배열은 0 5 9 12 14 15 이고
    // 만약 1 3 범위의 값을 구한다면 누적합을 담은 배열에서의 3번째에 해당하는 누적합 값은 12
    // 이고 1에 해당하는 누적합 값은 1 -1 = 0번째 이므로 빼주면 그 값이 나온다
    
    
    int stack_sum[n+1];
    stack_sum[0] = 0;
    
    for(int i = 1; i <= n; i++){
        stack_sum[i] = stack_sum[i-1] + arr[i-1];
        
    }

    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        cout << stack_sum[tmp2] - stack_sum[tmp1-1] << '\n';
    }
    
    
    
    return 0;
    
}