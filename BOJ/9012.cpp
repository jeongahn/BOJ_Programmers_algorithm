//baekjoon 9012 silver4 괄호

#include <iostream>
#include <string>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;

    cin >> T;

    string PS;

    
    for(int i = 0; i < T; i++){
        cin >> PS;
        int count = 1; // count를 1로 default값을 준 이유 : 0이면 ()의 경우에 count가 -1이 되어 NO가 출력
        int flag = 0;
        
        if(PS[0] != '(' || PS[PS.length()-1] != ')'){
            cout << "NO" << '\n';
            continue;
        }else{
            for(int j = 1; j < PS.length(); j++){ // 그렇기 때문에 처음을 제외한 끝까지 확인하여 count check
                if(PS[j] == '('){
                    count++;
                }else{
                    count--;
                }
                if(count < 0){
                    cout << "NO" << '\n'; // ( 보다 )가 연속으로 더 많아지는 순간 잘못된 괄호 이므로 NO 출력 후 break
                    flag = 1; // 반복문을 벗어난뒤에 최종적으로 YES, NO 출력을 할 때 중복 출력 방지를 위해
                    break;
                }
            }
        }
        if(count == 0 && flag == 0){
            cout << "YES" << '\n'; 
        }else if(count != 0 && flag == 0){
            cout << "NO" << '\n';
        }
    }
    return 0;
}