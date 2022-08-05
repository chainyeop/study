// 구글링을 통해 힌트를 얻어 해결하였다.
// 처음에는 이 문제가 지난 번에 백준 11053번을 풀 때 구했던 LIS랑 무슨 연관이 있는지 이해하지 못했다.
// 힌트를 보니 없애야하는 '전깃줄의 최소 개수'는 전체 전깃줄에서 '연결 가능한 가장 많은 전깃줄의 개수'를 뺀 값이라는 것이다.
// 이를 구하기 위해 왼쪽 전봇대의 수를 정렬하여 그에 맞게 오른쪽 수들을 옮긴 다음 
// 그 값들로 가장 긴 증가하는 부분수열을 구하는 것이다.
// 전체 전깃줄의 개수에서 위에서 구한 값을 빼주면 답을 구할 수 있다.
// 힌트를 보니 코드를 작성하는 과정은 크게 어렵지 않았다. 11053에서 사용했던 부분을 활용하였다.

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int arr[501]={0};
int dp[501]={0};
map<int,int> m;
map<int,int>::iterator iter;

int main(){
    int N,a,b;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        m.insert(pair<int,int>(a,b));
    }
    int k=0;
    for(iter=m.begin();iter!=m.end();iter++){
        arr[k]=iter->second;
        k++;
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<"\n";       
    }
    dp[0]=1;
    for(int i=1;i<N;i++){ // 가장 긴 증가하는 부분 수열을 구하는 코드. 백준 11053에 있는 코드를 이용했다.
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    sort(dp,dp+N+1);
    cout<<N-dp[N];
}