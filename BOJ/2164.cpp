//baekjoon 2164 silver4 카드2

#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> card;

    int N;

    cin >> N;

    for(int i = 1; i <= N; i++){
        card.push(i);
    }
    if(N == 1){
        cout << card.front() << '\n';
    }else{
        while(card.size() > 1){
            card.pop();
            int tmp = card.front();
            card.pop();
            card.push(tmp);
        }
        cout << card.front() << '\n';
    }

    return 0;
}