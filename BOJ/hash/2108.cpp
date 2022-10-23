//baekjoon 2108 silver3 통계학

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int>& a, pair<int, int>& b){ // 최빈값 비교함수
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    int range; // 중앙값, 범위
    
    unordered_map<int, int> c_um;
    vector<int> lst;
    int sum = 0; // 평균을 구하기 위한 값들의 총합
    
    
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        c_um[num]++;
        lst.push_back(num);
        sum += num;
    }

    sort(lst.begin(), lst.end());
    vector<pair<int, int>> tmp(c_um.begin(), c_um.end()); // 새로운 vector의 사용 접근법..!
    sort(tmp.begin(), tmp.end(), Compare);
    
    cout << int(round(double(sum) / N)) << '\n'; // 평균
     
    cout << lst[N / 2] << '\n';// 중앙값

    if(tmp[0].second == tmp[1].second) cout << tmp[1].first << '\n';
    else cout << tmp[0].first << '\n'; // 최빈값
    
    range = lst[N-1] - lst[0]; 
    cout << range << '\n'; // 범위
    
    return 0;
}