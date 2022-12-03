//baekjoon 9375 silver3 패션왕 신해빈  
//

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    

    int testCase;

    cin >> testCase;
    
    
    for(int i = 0; i < testCase; i++){
        map<string, int> m;
        int n;
        cin >> n;
        int total_sum = 1;
        
        for(int j = 0; j < n; j++){
            string name, form;
            cin >> name >> form;
            m[form] += 1;
        }



        for(auto i : m){
            
            total_sum *= (i.second + 1);
        }
        
        total_sum -= 1;

        cout << total_sum << '\n';
        

        
        
    }
    return 0;
    
}