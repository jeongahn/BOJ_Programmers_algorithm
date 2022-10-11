//baekjoon 10828 silver 4 스택

#include <iostream>
#include <string>

using namespace std;

int stack[10001] = {0, };
int Size = 0;

void push(int a){
    stack[Size++] = a;
}

int pop(){
    if(Size == 0){
        return -1;
    }else{
        return stack[--Size];
    }
}

int top(){
    if(Size == 0){
        return -1;
    }else{
        return stack[Size-1];
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

        if(s.size() >= 6){
            push(stoi(s.substr(5)));
            continue;
        }else if(s == "pop"){
            cout << pop() << '\n';
            continue;
        }else if(s == "top"){
            cout << top() << '\n';
            continue;
        }else if(s == "size"){
            cout << pSize() << '\n';
            continue;
        }else{
            cout << empty() << '\n';
            continue;
        }
    }

    return 0;
    
}
