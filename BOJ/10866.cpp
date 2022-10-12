//baekjoon 10866 silver 4 덱

#include <iostream>
#include <string>

using namespace std;

int deque[10001] = {0, };
int Size = 0;

void push_front(int a){
    int tmp[Size+1];
    for(int i = 1; i <= Size; i++){
        tmp[i] = deque[i-1];
    }
    tmp[0] = a;
    for(int i = 0; i <= Size; i++){
        deque[i] = tmp[i];
    }
    Size++;
}

void push_back(int a){
    deque[Size++] = a;
}

int pop_front(){
    int tmp = 0;
    if(Size == 0){
        return -1;
    }else{
        int front = deque[0];
        
        for(int i = 1; i < Size; i++){
            deque[tmp++] = deque[i];
        }
        Size--;
        return front;
    }
}

int pop_back(){
    if(Size == 0){
        return -1;
    }else{
        return deque[--Size];
    }
}

int front(){
    if(Size == 0){
        return -1;
    }else{
        return deque[0];
    }
}
int back(){
    if(Size == 0){
        return -1;
    }else{
        return deque[Size-1];
    }
}

int pSize(){
    return Size;
}

int empty(){
    if(Size == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    
    string s;

    for(int i = 0; i < N; i++){
        getline(cin, s);

        if(s.size() >= 8){
            if(s.substr(0,8) == "push_fro"){
                push_front(stoi(s.substr(11)));
            }else if(s.substr(0,8) == "push_bac"){
                push_back(stoi(s.substr(10)));
            }else if(s.substr(0,8) == "pop_fron"){
                cout << pop_front() << '\n';
            }else if(s.substr(0,8) == "pop_back"){
                cout << pop_back() << '\n';
            }
        }else{
            if(s == "front"){
                cout << front() << '\n';
                continue;
            }else if(s == "back"){
                cout << back() << '\n';
                continue;
            }else if(s == "size"){
                cout << pSize() << '\n';
                continue;
            }else{
                cout << empty() << '\n';
                continue;
            }
        }
    }

    return 0;
    
}
