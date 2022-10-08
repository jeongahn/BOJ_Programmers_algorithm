//baekjoon 10814 silver5 나이순 정렬

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int>b) {
	if(a.first.first == b.first.first){
        return a.second < b.second;
    // }else if(a.first.first < b.first.first){
    //     return a.first < b.first;
    }
    return a.first.first < b.first.first;
}


int main(){
    int testCase;
    cin >> testCase;
    int age;
    string Name;
    
    vector<pair<pair<int, string>, int>> n;

    for(int i =0; i < testCase; i++){
        cin >> age >> Name;
        n.push_back({{age, Name}, i});
        
    }
    sort(n.begin(), n.end(), compare);
    

    for(auto i : n){
        cout << i.first.first << " " << i.first.second << '\n';
    }

    // vector<pair<pair<int,int>,int> v;
    
    return 0;
    
}