//baekjoon 2407 silver4 조합

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pascal[101][101];
int n, m;


string addNumber(string a, string b){
    string result = "";
    int sum = 0;
    int Size = max(a.size(), b.size());

    for(int i = 0; i < Size || sum; i++){
        if(a.size() > i) sum += (a[i] - '0');
        if(b.size() > i) sum += (b[i] - '0');
        result += ((sum % 10) + '0');
        sum /= 10;        
    }

    return result;
}

string combination(int n, int m){
    if(n == m || m == 0){
        return "1";
    }
    string &tmp = pascal[n][m];
    if(tmp != ""){
        return tmp;
    }
    tmp = addNumber(combination(n-1, m-1), combination(n-1, m));

    return tmp;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    string Cresult = combination(n, m);
    reverse(Cresult.begin(), Cresult.end());

    cout << Cresult << '\n';

    return 0;

    
}