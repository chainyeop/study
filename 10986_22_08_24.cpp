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
        arr[sum]++;
        if(sum==0) cnt++;
    }
    for(int i=0;i<=1000;i++){
        cnt=cnt+(arr[i]*(arr[i]-1))/2;
    }
    cout<<cnt;
}