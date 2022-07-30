// 앞서 풀었던 백준 1149 문제처럼 점화식을 세워 그거대로 코드를 작성하였다.
// 중간에 계산한 값들이 겹치는 부분이 있었는데 크기에 상관없이 뒤에 계산한 값이 먼저 들어가는 문제가 있었다.
// 이 문제를 해결하는 것이 가장 힘든 부분이었다. for문 안에 다음과 같은 if문을 추가하여 해결할 수 있었다.
// n이 1일 경우에는 for문이 동작하지 않아 ans값에 바로 dp값을 넣어주었다.
#include<iostream>
#include<algorithm>
using namespace std;

int arr[501][501]={0};
int dp[501][501]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,num,ans=0,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>num;
            arr[i][j]=num;
        }
    }
    dp[1][1]=arr[1][1];
    if(n==1)
        ans=dp[1][1];
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            dp[i+1][j]=dp[i][j]+arr[i+1][j];
            dp[i+1][j+1]=dp[i][j]+arr[i+1][j+1];
            if(j>1) // a값과 현재 계산한 값을 비교 
                dp[i+1][j]=max(a,dp[i][j]+arr[i+1][j]);
            a=dp[i][j]+arr[i+1][j+1]; // 그 전 값을 저장함        
            ans=max({ans,dp[i+1][j],dp[i+1][j+1]});
        }
    }
    cout<<ans;
}