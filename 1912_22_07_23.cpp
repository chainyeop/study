// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int arr[1000][1000]={0};
// vector <int> v;

// void sum_dp(int n){
//     for(int i=1;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             arr[i][j]=arr[i-1][j]+arr[0][j+i];
//             v.push_back(arr[i][j]);
//         }
//     }
//     sort(v.begin(),v.end());
//     cout<<v.back();
// }

// int main(){
//     int n,num;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>num;
//         arr[0][i]=num;
//         v.push_back(num);
//     }
//     sum_dp(n);
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;

// int arr[100000][100000]={0};

// void sum_dp(int n){
//     int max=-9999;
//     for(int i=1;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             arr[i][j]=arr[i-1][j]+arr[0][j+i];
//             if(max<arr[i][j])
//                 max=arr[i][j];
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(max<arr[0][i])
//             max=arr[0][i];
//     }
//     cout<<max;
// }

// int main(){
//     int n,num;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>num;
//         arr[0][i]=num;
//     }
//     sum_dp(n);
// }

// 시작부터 완전히 잘못한 문제였다. 애초에 이중배열을 이용해 dp를 구현한다는건 말도 안되는 것이였다.
// 위에 있는 코드는 여기서는 실행이 되지만 백준에 제출하면 메모리 초과 등 다양한 오류가 발생했다.
// 구글링을 통해 어떻게 해결하는지를 봤는데 이해하는데도 굉장히 오래걸렸다.
// 단일 배열만으로도 충분히 해결할수 있는 문제였다. 
#include<iostream>
using namespace std;

int arr[100000]={0};
int dp[100000]={0};

int main(){
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        arr[i]=num;
    }
    int ans=arr[0];
    for(int i=0;i<n;i++){
        dp[i]=arr[i];
        if(i==0) continue;
        if(dp[i]<dp[i-1]+arr[i])
            dp[i]=dp[i-1]+arr[i];
        if(ans<dp[i])
            ans=dp[i];
    }
    cout<<ans;
}
