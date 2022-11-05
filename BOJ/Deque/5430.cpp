//baekjoon 5430 gold5 AC
//
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TestCase, n;
    string p; // 명령 함수
    string a;

    cin >> TestCase;

    for(int i = 0; i < TestCase; i++){
        deque<int> dq;
        cin >> p;
        cin >> n;
        bool err_check = false;
        bool re_check = false;
        // if(n == 0) err_check = true;
        cin >> a;
        

        string num_tmp = ""; // 배열에 1부터 100까지의 숫자가 오기때문에 [ , ] 사이의 
        //문자로된 숫자들을 합쳐서 숫자로 바꾸어 deque로 push

        
        for(int j = 0; j < a.length(); j++){
            if(a[j] == '[' || a[j] == ',' || a[j] == ']'){
                if(num_tmp == "") continue;
                dq.push_back(stoi(num_tmp));
                num_tmp = "";
                continue;
            }
            num_tmp += a[j];
        }
        
        
        int tmp;
        for(int j = 0; j < p.length(); j++){
            if(p[j] == 'R'){
                re_check = !re_check;
            }else{
                if(dq.empty()){
                    err_check = true;
                    break;
                }else{
                    if(re_check){
                        dq.pop_back();
                    }else{
                        dq.pop_front();
                    }
                }
            }
        }

        // if(dq.empty()) err_check = true;
        
        if(err_check){
            cout << "error" << '\n';
        }else{
            cout << '[';
            if(re_check){
                for(int j = 0; j < dq.size(); j++){
                    if(j == dq.size() -1){
                        cout << dq.back();
                        break;
                    }
                    cout << dq.back() << ',';
                    tmp = dq.back();
                    dq.pop_back();
                    dq.push_front(tmp);
                }
                cout << ']' << '\n';
            }else{
                for(int j = 0; j < dq.size(); j++){
                    if(j == dq.size() -1){
                        cout << dq.front();
                        break;
                    }
                    cout << dq.front() << ',';
                    tmp = dq.front();
                    dq.pop_front();
                    dq.push_back(tmp);
                }
                cout << ']' << '\n';
            }
        }
    }
    return 0;
}