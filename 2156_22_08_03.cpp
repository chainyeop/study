// 기본적인 점화식은 잘 세웠다. 그런데 한가지 간과했던 사실이 있었다.
// 그 전의 dp값이 더 클수도 있기 때문에 최댓값을 구해줄 때 dp[i-1]을 포함시켜줘야 했다.
// 같은 맥락으로 dp[3]에서도 max안에 dp[2]를 포함시켜 주었다.
#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001]={0};
int arr[10001]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,num;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num;
        arr[i]=num;
    }
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    dp[3]=max({dp[2],arr[1]+arr[3],arr[2]+arr[3]}); 
    for(int i=4;i<=n;i++)
        dp[i]=max({dp[i-1],dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]});
    sort(dp,dp+n+1);
    cout<<dp[n];
}