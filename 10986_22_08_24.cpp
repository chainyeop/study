// 처음에는 일단 dp를 이용해 풀어보았지만 역시나 시간초과가 떴다.
// 시간초과를 피하기 위해 고민을 하다 결국 구글링을 하여 도움을 받았다.
// 이전에 풀었던 구간합 문제에서 사용한 %를 이용한 공식이 한번더 활용되었다.
// 합을 배열에 저장하는 것이 아니라 누적합을 M으로 나눈 나머지를 배열에 저장하는 식으로 해결하였다.
// 그렇게하여 배열의 크기가 천 단위로 줄어들고 시간도 크게 단축시킬수 있었다.

// #include<iostream>
// using namespace std;

// int dp[1000001]={0};

// int main(){
//     int N,M,num,cnt=0;
//     cin>>N>>M;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         dp[i]=(dp[i-1]+num)%M;
//         if(dp[i]==0) cnt++;
//     }
//     for(int i=1;i<N;i++){
//         for(int j=i+1;j<=N;j++){
//             if(dp[i]==dp[j])
//                 cnt++;
//         }
//     }
//     cout<<cnt;
// }

#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,M,num,sum=0,arr[1001]={0},cnt=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>num;
        sum=(sum+num)%M;
        arr[sum]++; // 누적합의 나머지를 인덱스로 사용해 배열의 값을 카운트한다.
        if(sum==0) cnt++;
    }
    for(int i=0;i<=1000;i++){
        cnt=cnt+(arr[i]*(arr[i]-1))/2;
    }
    cout<<cnt;
}