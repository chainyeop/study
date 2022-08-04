// 시간을 줄이기 위해 값을 입력 받을 때마다 dp의 값을 구해주었다.
// 점화식을 일찍 발견하여 생각보다 빠르게 해결할 수 있었다.
#include<iostream>
using namespace std;

int dp[1025][1025]={0};

int main(){
    int N,M,num,ans;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>num;
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+num;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    int x1,x2,y1,y2;
    for(int i=0;i<M;i++){
        cin>>x1>>y1>>x2>>y2;
        ans=dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1];
        cout<<ans<<"\n";
    }
}