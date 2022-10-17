//baekjoon 2609 bronze1 최대공약수와 최소공배수

#include <iostream>

using namespace std;

int gcd(int N, int M) {
	int c = N % M;
	while (c != 0) {
		N = M;
		M = c;
		c = N % M;
	}
	return M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;

    cin >> N >> M;

    int max, min;

    min = gcd(N, M);

    max = (N * M) / min;

    cout << min << '\n' << max << '\n';

    return 0;
}