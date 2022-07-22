#include<iostream> 
using namespace std;

long long dp[1000000]={0};

long long binary_dp(int n){
    if(dp[n]==0){
        if (n <= 2) dp[n]=n;
        else dp[n]=binary_dp(n - 1) + binary_dp(n - 2);
    }

    return dp[n]%15746;
}
int main(){
    int N;
    cin>>N;
    cout<<binary_dp(N);
}
