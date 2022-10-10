//baekjoon 2751 silver5 수 정렬하기 2
//merge sort로 문제 풀이
//merge sort란 
#include <iostream>
#include <vector>
using namespace std;


int tmp[1000000]; // 사실 baekjoon 문제 풀다가 정리하기로 마음 먹어서..

void merge(int arr[], int start, int end){
	int mid = (start + end) / 2;
	
	int left_idx = start, right_idx = mid + 1, k = start;
	//left_idx = 왼쪽 부분배열의 인덱스, right_idx = 오른쪽 부분배열의 인덱스, k: 현재까지 병합 한 인덱스


	while(left_idx<=mid && right_idx<=end){
        if(arr[left_idx]<=arr[right_idx])
            tmp[k++] = arr[left_idx++];
        else
        tmp[k++] = arr[right_idx++];
    }

  // 남아 있는 값들을 일괄 복사
    if(left_idx>mid){
        for(int i = right_idx; i<=end; i++)
        tmp[k++] = arr[i];
    }
  // 남아 있는 값들을 일괄 복사
    else{
        for(int i = left_idx; i<=mid; i++)
        tmp[k++] = arr[i];
    }

  // 배열 tmp[](임시 배열)의 리스트를 배열 arr[]로 재복사
    for(int i = start; i <= end; i++) arr[i] = tmp[i];
}

    
	

void merge_sort(int arr[], int start, int end){
	if(start < end){
	   int mid = (start + end) / 2;
	   merge_sort(arr, start, mid);
	   merge_sort(arr, mid + 1, end);
	   merge(arr, start, end);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;
    int result[N];
    for(int i = 0; i < N; i++){
        cin >> num;
        result[i] = num;
    }
    
	merge_sort(result, 0, N-1);
	
	for(auto i : result){
		cout << i << '\n';
	}
	return 0;
}