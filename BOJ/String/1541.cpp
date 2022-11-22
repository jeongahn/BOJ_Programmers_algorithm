//baekjoon 1541 silver2 잃어버린 괄호  

#include <iostream>
#include <string>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string s;
    cin >> s;
    
    string pre = "";
    int curr = 0;
    bool sub_check = false;

    
    for (int i = 0; i <= s.size(); i++) {
        
        if (s[i] == '-' || s[i] == '+' || i==s.size()) {
            if (sub_check) {
                curr -= stoi(pre);
                pre = "";
            }
            else {
                curr += stoi(pre);
                pre = "";
            }
        }
        else {
            pre += s[i];
        }
 
        if (s[i] == '-') {
            sub_check = true;
        }    
    }


    cout << curr << '\n';
    
    
    return 0;
    
}