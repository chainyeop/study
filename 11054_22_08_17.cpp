// 처음에 했던 생각은 배열의 수중 가장 큰 값을 기준으로 좌, 우로 가장 긴 부분 수열들을 수해주면 될 것이라고 생각했다.
// 그러나 이 방법으로는 반례들을 모두 해결할 수가 없었다.

// #include<iostream>
// using namespace std;

// int dp[1001]={0};
// int dp2[1001]={0};
// int dp3[1001]={0};
// int arr[1001]={0};

// int main(){
//     int N,num,index=1,upMax=1,downMax=1;
//     cin>>N;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     dp[1]=1;
//     int idx=1,amax=arr[1];
//     for(int i=2;i<=N;i++){
//         dp[i]=1;
//         if(amax<arr[i]) idx=i;
//         amax=max(amax,arr[i]);
//         //if(amax>arr[i]) idx=i-1;

//         for(int j=1;j<i;j++){
//             if(arr[i]>arr[j])
//                 dp[i]=max(dp[i],dp[j]+1);
//             if(upMax<dp[i]){
//                 upMax=dp[i];
//                 index=i;
//             }
//         }
//     }
//     cout<<upMax<<" "<<index<<" ";
//     dp2[index]=1;
//     for(int i=index+1;i<=N;i++){ // case1
//         for(int j=index;j<i;j++){
//             if(arr[i]<arr[j])
//                 dp2[i]=max(dp2[i],dp2[j]+1);
//             if(downMax<dp2[i])
//                 downMax=dp2[i];
//         }
//     }
//     int down=1;
//     dp3[idx]=1;
//     for(int i=idx+1;i<=N;i++){ // case2
//         dp3[i]=1;
//         for(int j=idx;j<i;j++){
//             if(arr[i]<arr[j])
//                 dp3[i]=max(dp3[i],dp3[j]+1);
//             if(down<dp3[i])
//                 down=dp3[i];
//         }
//     }
//     cout<<downMax<<" "<<"amax"<<amax<<" "<<idx<<"\n";
//     cout<<"down"<<down;
//     cout<<"result"<<upMax+downMax-1<<" "<<dp[idx]+down-1;
// }

// 구글링을 통해 힌트를 찾아보니 왼쪽에서 오른쪽으로 가는 가장 긴 부분 수열과 
// 오른쪽에서 왼쪽으로 가는 가장 긴 부분 수열을 구해서 해결하였다.
// 생각지도 못한 방법이어서 신기했다. 

#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001]={0};
int dp2[1001]={0};
int arr[1001]={0};

int main(){
    int N,num;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num;
        arr[i]=num;
    }
    dp[1]=1;
    for(int i=2;i<=N;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    dp2[N]=1;
    for(int i=N-1;i>=1;i--){
        dp2[i]=1;
        for(int j=N;j>i;j--){
            if(arr[i]>arr[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }
    int result[1001]={0};
    for(int i=1;i<=N;i++){
        result[i]=dp[i]+dp2[i];
    }
    sort(result,result+N+1);
    cout<<result[N]-1;
}


