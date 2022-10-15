//baekjoon 1094 silver5 막대기

#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector <int> result;

    int ori = 64;
    int count = 0;
    int X;

    cin >> X;

    int sum = 0;

    if(X == ori){
        count = 1;
    }else{
        while(sum != X){
            sum = 0;
            ori /= 2;
            result.push_back(ori);

            vector<int>::iterator iter = result.begin();
            for(; iter != result.end(); iter++){
                sum += *iter;
            }
            
            if(sum >= X){
                result.pop_back();
                continue;
            }else{
                continue;
            }
        }
        count = result.size() + 1; // 마지막에 pop_back()이 하나 되었기 때문에 다시 1을 더해준다
    }

    cout << count << '\n';

    return 0;
}

// 비트마스킹 알고리즘으로 다시 풀어보기!!
//