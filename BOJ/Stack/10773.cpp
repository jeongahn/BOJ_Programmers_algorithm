//baekjoon 10773 silver4 제로

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int K;
    stack<int> acnt_B;
    cin >> K;

    for(int i = 0; i < K; i++){
        int num;
        cin >> num;
        if(num == 0){
            acnt_B.pop();
        }else{
            acnt_B.push(num);    
        }
    }
    int sum = 0;
    int length = acnt_B.size();
    for(int i = 0; i < length; i++){
        sum += acnt_B.top();
        acnt_B.pop();
    }

    cout << sum << '\n';
    
    
    return 0;
}