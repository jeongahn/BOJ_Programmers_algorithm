//beakjoon 1152 bronze 2 단어의 개수

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;

    getline(cin, S);
    
    istringstream ss(S);
    string stringBuffer;
    vector<string> v;
    vector<string> result;
    v.clear();
    //구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
    while (getline(ss, stringBuffer, ' ')) {
        v.push_back(stringBuffer);
    }
 
    for(int i = 0; i < v.size(); i++){
        if(v[i] != ""){
            result.push_back(v[i]);
        }
    }
    cout << result.size() << '\n';
    
    
    return 0;
    
}
