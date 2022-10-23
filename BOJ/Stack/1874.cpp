//baekjoon 1874 silver2 스택 수열

#include <iostream>
#include <stack>
#include <string>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string result;
    stack<int> s;

    int s_Top = 0;
    
    while(N--){
        int num;
        cin >> num;

        if(num > s_Top){
            while(num > s_Top){
                s.push(++s_Top);
                result += '+';
            }
            s.pop();
            result += '-';
        }else{
            bool check = false;
            if(!s.empty()){
                if(num == s.top()){
                    check = true;
                }
                s.pop();
                result += "-";
            }
            if(!check){
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    for(auto i : result){
        cout << i << '\n';
    }
    
    return 0;
}