//baekjoon 7568 silver5 덩치

#include <iostream>
#include <vector>

using namespace std;
int grade[51];
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    fill_n(grade, 51, 1);
    
    int N;
    int x, y;

    cin >> N;
    
    vector<pair<int, int>> list;
    
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        list.push_back({x, y});
    }

    

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }else{
                if(list[i].first < list[j].first && list[i].second < list[j].second){
                    grade[i]++;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << grade[i] << " ";
    }
    cout << '\n';

    return 0;
}