// 마찬가지로 저번학기에 사용했던 알고리즘 교재를 참고하였다.
// 다른 문제들과 달리 생각보다 쉬웠다.
// LCS자체를 출력하거나 그런거 없이 길이만 출력하면 되기 때문이었는지도 모르겠다.
// 코드도 어렵지 않아서 이해가 빨리 되었다.

#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][1001]={0};

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }   
    }
    cout<<dp[a.size()][b.size()];
}