//baekjoon 1049 silver4 기타줄

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M; // 끊어진 기타줄의 개수 N, 기타줄 브랜드 M개
    cin  >> N >> M;

    
    int p_lst[M];
    int i_lst[M];
    
    int pak_p, ind_p; // 패키지 가격, 낱개 가격 변수
    int need_pak; // 패키지만 구입시 최소로 사야 되는 패키지 개수

    int result[3];
    int min_price = 1001; // 돈의 최솟값, 초기값은 범위 최대보다 1 많게 설정

    if(N % 6 != 0){
        need_pak = (N / 6) + 1;
    }else{ // 내가 실수해서 쓰지 못한 코드.. 딱 패키지의 배수 만큼 있을때 필요한 패키지의 개수도 할당 했어야지!!!
        need_pak = N / 6;
    }
    
    for(int i = 0; i < M; i++){
        cin >> pak_p >> ind_p;
        p_lst[i] = pak_p;
        i_lst[i] = ind_p;
    }

    int p_min = *min_element(p_lst, p_lst + M); // 패키지 최솟값
    int i_min = *min_element(i_lst, i_lst + M); // 낱개 최솟값

    result[0] = need_pak * p_min; //1. 패키지만 사는 경우 가격

    result[1] = N * i_min; //2. 낱개만 사는 경우 가격

    result[2] = (N / 6) * p_min + (N % 6) * i_min; // 패키지, 낱개 둘다 섞어서 사는 경우

    min_price = *min_element(result, result + 3);
    
    
    cout << min_price << '\n';
    
    return 0;
}