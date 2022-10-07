//baekjoon 1920 silver4 수 찾기

#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(int arr[], int key, int n) {
	int low, mid, high;

	low = 0;
	high = n - 1;

	while (1) {
		mid = (high + low) / 2;

		if (arr[mid] == key) return 1;
		if (arr[low] == key) return 1;
		if (arr[high] == key)  return 1;

		if (arr[mid] < key) low = mid + 1;
		else high = mid - 1;
		
		if (high <= low) return 0;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int N, M;
    cin >> N;
    int arrN[N];
    for(int i = 0; i < N; i++){
        cin >> arrN[i];
    }
    sort(arrN, arrN+N);

    cin >> M;
    int arrM[M];
    for(int i = 0; i < M; i++){
        cin >> arrM[i];
        arrM[i] = BinarySearch(arrN, arrM[i], N);
    }

    for(int i = 0; i < M; i++){
        cout << arrM[i] << '\n';
    }

    
    return 0;
}