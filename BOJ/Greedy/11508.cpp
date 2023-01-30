// baekjoon 11508 silver4 2+1세일
// 23년 상반기 Foscar 알고리즘 스터디 3조 2주차 3번
// 그리디 알고리즘


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b){
    return a > b;
}

int main(){
    int n;
    int cost;
    int min_cost = 0;

    vector<int> v;
    

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> cost;
        v.push_back(cost);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++){
        if(i % 3 != 2) min_cost += v[i];
    }

    cout << min_cost << '\n';



}