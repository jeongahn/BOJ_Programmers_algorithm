// baekjoon 1436 silver 5 영화감독 숌
// 브루트포스.. 생각하기 힘들었던..

#include <iostream>

using namespace std;

int main(){
    int N, temp;
    int count = 0;
    int first = 666;

    cin >> N;
    
    while(1){
        temp = first;
        do{ 
            if(temp % 1000 == 666){
                count++;
                break;
            }
            temp /= 10;
            
        }while(temp>0);

        if(count == N){
            cout << first << '\n';
            break;
        }
        first++;
    }

    return 0;
}
// find함수를 구현해서 문자열 내에 666이 포함되어있는지 확인 하는 방법 위 방법보다 오래 걸린다.
// #include <iostream>
// #include <string>
// using namespace std;
// int Findseries(int N)
// {
//     int i = 666;
//     int series = 0;
//     string target;
//     while(1)
//     {
//         target = to_string(i);
//         for(int j = 0; j < target.length()-2; j++)
//             if(target[j] == '6' && target[j+1] == '6' && target[j+2] == '6')
//             {
//                 series++;
//                 if(series == N)
//                     return i;
//                 break;
//             }
//         i++;
//     }
// }
// int main() {
//     int N;
//     cin >> N;
//     cout << Findseries(N);
// }