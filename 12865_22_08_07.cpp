#include<iostream>
#include<algorithm>
using namespace std;

int dp[101][100001]={0};

int main(){
    int N,K,W,V,warr[100]={0},varr[100]={0};
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>W>>V;
        warr[i]=W;
        varr[i]=V;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(warr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                int contain=varr[i-1]+dp[i-1][j-warr[i-1]];
                int ncontain=dp[i-1][j];
                dp[i][j]=max(contain,ncontain);
            }
        }
    }
    cout<<dp[N][K];
}