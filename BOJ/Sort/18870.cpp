//baekjoon 18870 silver2 좌표 압축 
//ex) 5
//    2 4 -10 4 -9
//위 입력을 받았을때 출력은 2 3 0 3 1
//이 문제는 만약 2를 압축했을때 2보다 작은 서로 다른 좌표의 개수와 같은 값이 압축값이 되어야 한다
//즉 2 4 -10 4 -9를 sort하면 -10 -9 2 4 4
//각 값보다 작은 값들의 개수로 압축값이 되므로 -> 0 1 2 3 3
//sort되기전 원래의 위치로 값을 할당하면 2 3 0 3 1 출력이 나온다

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v1; //sort후 중복제거해서 압축값들을 담을 배열
    vector<int> v2; //출력을 위해 실제 압축되기전 값들을 담을 배열
    map<int, int> m; //압축되기 전 값과 압축된 값들을 담을 map
    
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
        v2.push_back(tmp);
    }
    
    sort(v1.begin(), v1.end());

    //algorithm header file의 unique함수는 unique(x,y)일때
    //x부터 y까지 중복된 값이 나온 값을 하나 빼고 나머지는 맨뒤로 보내고 그 인덱스를 리턴한다
    //즉 처음부터 끝까지 배열에 담긴 값들중 중복된 값들을 하나씩만 앞에 나열한 후
    //중복된 값들이 맨뒤로 보내진 시작점의 인덱스를 리턴하므로
    //erase(x,y)는 x부터 y까지 제거 - erase함수로 중복 값들을 제거한다

    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    

    // cout << v1.size() << '\n'; echo checking
    
    for(int i = 0; i < v1.size(); i++){
        m[v1[i]] = i;
    }

    for(int i = 0; i < v2.size(); i++){
        cout << m[v2[i]] << '\n';
    }

    return 0;
}