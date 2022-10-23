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
        }else{// 예를 들어 4가 먼저 출력되고 3이 출력되어야 할때 3은 이미 stack에 있기 때문에 4가 pop이 되어 출력된뒤 남은 stack의 top이 되므로 출력이 가능하다.
            // 하지만 2가 출력되어야한다면 3을 pop한뒤에 출력이 가능하기 때문에 이런 경우 check = false로 NO를 출력한다.
            // 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자 라고 했기 때문에 4다음 3을 pop한걸 다시 push 하면 되지 않나라는 개념은 불가능 
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