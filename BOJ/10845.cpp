//baekjoon 10845 silver 4 큐

#include <iostream>
#include <string>

using namespace std;

int queue[10001] = {0, };
int Size = 0;

void push(int a){
    queue[Size++] = a;
}

int pop(){
    int tmp = 0;
    if(Size == 0){
        return -1;
    }else{
        int front = queue[0];
        
        for(int i = 1; i < Size; i++){
            queue[tmp++] = queue[i];
        }
        Size--;
        return front;
    }
}

int front(){
    if(Size == 0){
        return -1;
    }else{
        return queue[0];
    }
}
int back(){
    if(Size == 0){
        return -1;
    }else{
        return queue[Size-1];
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
        }else if(s == "front"){
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

    return 0;
    
}
