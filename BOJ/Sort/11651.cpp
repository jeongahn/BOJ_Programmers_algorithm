//baekjoon 11651 silver5 좌표 정렬하기2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<pair<int, int>> crd;
    
    cin >> N;

    int x,y;

    for(int i = 0; i < N; i++){
        cin >> x >> y;
        crd.push_back(make_pair(x,y));
    }

    sort(crd.begin(), crd.end(), Compare);

    for(int i = 0; i < N; i++){
        cout << crd[i].first << " " << crd[i].second << '\n';
    }
    
    
    
    return 0;
}