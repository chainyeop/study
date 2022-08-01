// 처음에 dp[i]=2*dp[i-1]-i+1라는 점화식을 세워서 쉽게 풀었다고 생각했었다.
// 그러나 그것은 내 착각이었고 5이상부터는 저 식이 맞지 않는다는것을 알고 처음부터 다시 풀었다.
// #include<iostream> 
// using namespace std;

// long long dp[101]={0};

// int main(){
//     int N;
//     cin>>N;
//     dp[1]=9;
//     for(int i=2;i<=N;i++){
//         dp[i]=(2*dp[i-1]-i+1)%1000000000;
//     }
//     cout<<dp[N];
// }

// j가 1일 때, 9일 때, 그 이외에 수의 3가지로 나눠서 해결하였다.
// 더한 값들을 sum에 넣고 이 값을 dp[i][10]에 넣어줄 때도 10억으로 나눠주어야 했다.
// 처음에는 나누지 않고 바로 넣어서 틀렸었는데 왜 이때도 나눠주어야 하는지는 정확히 모르겠다.
#include<iostream>
using namespace std;

long long dp[101][11]={0};

int main(){
    int N;
    cin>>N;
    dp[0][1]=1;
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
        dp[1][10]+=dp[1][i];
    }
    for(int i=2;i<=N;i++){
        long long sum=0;
        for(int j=1;j<=9;j++){
            if(j==1){
                dp[i][j]=(dp[i-1][j+1]+dp[i-2][j])%1000000000;
            }
            else if(j>1 && j<=8){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
            }
            else if(j==9){
                dp[i][j]=(dp[i-1][j-1])%1000000000;
            }
            sum=sum+dp[i][j];
        }
        dp[i][10]=sum%1000000000;
    }
    cout<<dp[N][10];
}