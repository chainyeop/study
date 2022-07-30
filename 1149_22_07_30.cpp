// 처음 봤을 때 어떻게 해결할지 감을 못잡아서 굉장히 고민을 많이 했던 문제였다.
// 하지만 알고보니 백준 1912번 문제를 해결하는 것과 거의 동일한 방법을 사용하면 쉽게 해결 가능했다.
// 단지 시작을 어디에서 하느냐에 따라 3가지로 나누어주기만 하면 되었던 문제였다.
// 시작 위치에 따라 점화식을 세워 그에 맞게 코드를 작성했다.
// 풀이 방법을 알고나니 1912번을 풀 때 처럼 하면 됐을텐데 하는 아쉬움이 남았다. 
#include<iostream>
#include<algorithm>
using namespace std;

int arr[1010][3]={0};
int dp[1010][3]={0};

int main(){
    int N,a,b,c,sum=0,MIN;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a>>b>>c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }
    for(int i=1;i<=N;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0]; // R부터 칠하는 경우
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1]; // G부터 칠하는 경우
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2]; // B부터 칠하는 경우
    }
    MIN=min({dp[N][0],dp[N][1],dp[N][2]});
    cout<<MIN;
}