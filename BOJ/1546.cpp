//baekjoon 1546 bronze 1 평균

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int test_num;

    cin >> test_num;

    double test_arr[test_num];
    double N;
    double max_num = 0;
    
    for(int i = 0; i < test_num; i++){
        cin >> N;
        max_num = max(max_num, N);
        test_arr[i] = N;
    }
    
    double sum = 0; // 평균을 구하기 위한 모든 시험 과목의 합 변수
    
    for(int i = 0; i < test_num; i++){
        test_arr[i] = test_arr[i] / max_num * 100;
        sum += test_arr[i];
    }

    cout << sum / test_num << '\n';

    return 0;
    
}