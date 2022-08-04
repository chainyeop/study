// 아래의 코드로 하다가 계속 실패하여 그 밑에 코드로 다시 작성했다.
// 게시판에 있는 반례들을 다 넣어봤지만 아래의 코드가 왜 실패하는지 아직 이유를 알아내지 못했다.

// #include<iostream>
// #include<algorithm>
// using namespace std;

// int dp[1001]={0};

// int main(){
//     int N,num,arr[1001]={0},a=0;
//     cin>>N;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     dp[1]=1;
//     int cnt=1;
//     for(int i=2;i<=N;i++){
//         if(arr[i]>arr[i-1]){
//             if(arr[i]<=arr[cnt]){
//                 dp[i]=dp[i-1]+1;
//                 if(dp[i]>=dp[cnt])
//                     cnt=i;
//             }
//             else if(arr[i]>arr[cnt]){
//                 dp[i]=max(dp[i-1]+1,dp[cnt]+1);
//                 cnt=i;
//             }
//         }
//         else{
//             a=0;
//             for(int j=1;j<i;j++){
//                 if(arr[i]>arr[j]){
//                     if(a<dp[j])
//                         a=dp[j];
//                 }
//                 dp[i]=a+1;
//             }
//             if(dp[i]>=dp[cnt])
//                 cnt=i;
//         }
//     }
//     for(int i=1;i<=N;i++){
//         cout<<dp[i]<<" ";
//     }
//     sort(dp,dp+N+1);
//     cout<<"\n";
//     for(int i=1;i<=N;i++){
//         cout<<dp[i]<<" ";
//     }
//     cout<<"\n";
//     cout<<"ans "<<dp[N];
//     cout<<"ans "<<dp[cnt];
// }

// 구글링을 통해 힌트를 얻어 해결했다.
// 이중 for문과 dp를 동시에 사용하여 해결하는 문제였다.

#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001]={0};

int main(){
    int N,num,arr[1001]={0};
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num;
        arr[i]=num;
    }
    dp[1]=1;
    int cnt=0;
    for(int i=2;i<=N;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    sort(dp,dp+N+1);
    cout<<dp[N];
}
