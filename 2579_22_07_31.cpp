// 쉽게 해결할수 있을거라 생각했지만 그렇지 않았다.
// 점화식을 세우는 부분이 가장 문제였다. 고민 끝에 결국 구글링을 통해 힌트를 얻어 문제를 해결했다.
#include<iostream>
#include<algorithm>
using namespace std;

int arr[301]={0};
int dp[301]={0};

int main(){
    int N,num;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num;
        arr[i]=num;
    }
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    dp[3]=max(arr[1]+arr[3],arr[2]+arr[3]);
    for(int i=4;i<=N;i++){
        dp[i]=max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
    }
    cout<<dp[N];
}