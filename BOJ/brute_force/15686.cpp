#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,m,chicken_num;
int result = 99999999;
int city_map[51][51];
vector<pair<int, int>> house_loc, chicken_loc, enable;
bool selection[13]; // m이 최대 13

int Min(int a, int b){
    if (a < b) return a;
    return b;
}


int cal_min_dist(){
    int dist = 0;

    for(int i = 0; i < house_loc.size(); i++){
        int h_y = house_loc[i].first;
        int h_x = house_loc[i].second;
        int tmp_dist = 99999999;

        for (int j = 0; j < enable.size(); j++){
            int e_y = enable[j].first;
            int e_x = enable[j].second;
            int d = abs(e_y-h_y) + abs(e_x-h_x);

            tmp_dist = Min(tmp_dist, d);
        }
        dist = dist + tmp_dist;
    }

    return dist;
}

void select_Chicken(int idx, int cnt){
    if(cnt == m){
        result = Min(result, cal_min_dist());
        return;
    }

    for(int i = idx; i < chicken_num; i++){
        if(selection[i] == true) continue;
        selection[i] = true;
        enable.push_back(chicken_loc[i]);
        select_Chicken(i, cnt + 1);
        selection[i] = false;
        enable.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;
    


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> city_map[i][j];
            if(city_map[i][j] == 1) house_loc.push_back(make_pair(i, j));
            if(city_map[i][j] == 2) chicken_loc.push_back(make_pair(i,j)); 
        }
    }

    chicken_num = chicken_loc.size();

    select_Chicken(0,0);

    cout << result << '\n';
    
    return 0;
}