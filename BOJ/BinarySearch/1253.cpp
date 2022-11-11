//baekjoon 1253 gold4 좋다 
//이진 탐색

#include <iostream>
#include <algorithm>

using namespace std;

int arr[2001]; // 수의 개수가 2000개 이하

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    int left, right;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N); // 주어진 수를 이진 탐색하기 위해 정렬
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int curr = arr[i]; // 현재 확인하려는(다른 수 두개의 합으로 나타낼 수 있는지) 수 
        left = 0, right = N - 1; 

        while(left < right){
            if(arr[left] + arr[right] == curr){
                if(left != i && right != i){ // ex) 0 0 3의 경우는 답이 0, 본인을 제외한 다른 두 수, 위치가 다르면 값이 같아도 다른 것으로 인정
                    cnt++;
                    break;
                }
                else if(left == i) left++; // 현재 그 수의 위치에 해당하면 벗어남
                else if(right == i) right--;
            }else if(arr[left] + arr[right] < curr){ 
                left++;
            }else{
                right--;
            }
        }
    }
    cout << cnt << '\n';
    
    

    return 0;
}