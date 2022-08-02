#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int N,num,ans=0;
    vector <int> v;
    int sum[1001]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            sum[i]=sum[i-1]+v[i-1];
        }
        ans+=sum[i];
    }
    cout<<ans;
}