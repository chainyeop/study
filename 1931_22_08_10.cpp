// 처음에는 dp에 나왔던 LIS와 비슷한 문제라고 생각하여 dp를 이용하여 해결하려고 시도했다.
// 혹여나 메모리 초과가 뜰 수도 있겠다는 생각을 했었는데 시간 초과가 떠서 놀랐었다.
// 아무래도 이중 반복문을 돌다 보니 시간 복잡도가 O(n^2)이 되어서 그랬을 것이다.

// #include<iostream>
// #include<algorithm>
// using namespace std;

// int dp[10000]={0};

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N,a,b,arr[10000][2]={0};
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>a>>b;
//         arr[i][0]=a;
//         arr[i][1]=b;
//     }
//     dp[0]=1;
//     for(int i=1;i<=N;i++){
//         dp[i]=1;
//         for(int j=0;j<i;j++){
//             if(arr[i][0]>=arr[j][1])
//                 dp[i]=max(dp[i],dp[j]+1);
//         }
//     }
//     sort(dp,dp+N);
//     cout<<dp[N-1];
// }

// 구글링을 통해 힌트를 얻어 해결하였는데 vector와 pair를 이용하여 해결했다.
// 예전에 비슷한 문제를 해결했었는데 입력 받는 값의 위치를 바꿔 vector에 넣어서 해결했다.
// v벡터에 값을 넣을 때 b, a의 순서로 값을 넣었다.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,a,b,cnt=1;
    vector <pair<int,int>> v;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    int time=v[0].first;
    for(int i=1;i<N;i++){
        if(time<=v[i].second){
            time=v[i].first;
            cnt++;
        }
    }
    cout<<cnt;
}
