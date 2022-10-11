//baekjoon 11650 silver5 좌표 정렬하기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> coord;

    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        coord.push_back({x, y});
    }
    sort(coord.begin(), coord.end(), compare);

    for(auto i : coord){
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}