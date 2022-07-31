
// #include<iostream> // 하향식
// #include<algorithm>
// using namespace std;

// int dp[1000010]={0};

// int func(int n){
//     if(dp[n]!=0) return dp[n];
//     if(n<=3) return dp[n];

//     if(n%2==0 && n%3==0)
//         dp[n]=min({1+func(n/2),1+func(n/3),1+func(n-1)});
//     else if(n%2==0)
//         dp[n]=min(1+func(n/2),1+func(n-1));
//     else if(n%3==0)
//         dp[n]=min(1+func(n/3),1+func(n-1));
//     else
//         dp[n]=1+func(n-1);

//     return dp[n];
// }

// int main(){
//     int X;
//     cin>>X;
//     dp[1]=0,dp[2]=1,dp[3]=1;
//     cout<<func(X);
// }

// #include<iostream> // 상향식
// #include<algorithm>
// using namespace std;

// int dp[1000010]={0};

// int main(){
//     int X;
//     cin>>X;
//     dp[1]=0,dp[2]=1,dp[3]=1;
//     for(int i=4;i<=X;i++){
//         dp[i]=dp[i-1]+1;
//         if(i%2==0 && i%3==0)
//             dp[i]=min({1+dp[i/2],1+dp[i/3],1+dp[i-1]});
//         else if(i%3==0)
//             dp[i]=min(dp[i/3]+1,dp[i-1]+1);
//         else if(i%2==0)
//             dp[i]=min(dp[i/2]+1,dp[i-1]+1);
//         else
//             dp[i]=dp[i-1]+1;
//     }
//     cout<<dp[X];
// }

#include<iostream> // 상향식
#include<algorithm>
using namespace std;

int dp[1000010]={0};

int main(){
    int X;
    cin>>X;
    dp[1]=0,dp[2]=1,dp[3]=1;
    for(int i=4;i<=X;i++){
        dp[i]=dp[i-1]+1;
        if(i%3==0)
            dp[i]=min(dp[i/3]+1,dp[i]);
        if(i%2==0)
            dp[i]=min(dp[i/2]+1,dp[i]);
    }
    cout<<dp[X];
}