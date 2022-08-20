#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> v[101];
int visitied[101]={0};
int ans[101]={0},cnt=0;

void dfs(int r){
    visitied[r]=1;
    cnt++;
    ans[r]=cnt;
    for(int i=0;i<v[r].size();i++){
        if(visitied[v[r][i]]==0)
            dfs(v[r][i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,a,b;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        sort(v[i].begin(),v[i].end());
    }
    dfs(1);
    sort(ans,ans+N+1);
    // for(int i=1;i<=N;i++){
    //     cout<<ans[i]<<"\n";
    // }
    cout<<ans[N]-1;
}