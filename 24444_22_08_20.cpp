// 백준 24445번은 이 코드에서 오름차순 대신 내림차순만 적용한거라 따로 만들지 않았음

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector <int> graph[100001];
queue <int> q;
int visited[100001]={0},cnt=1;
int num[100001]={0};

void bfs(int n,int m,int r){
    visited[r]=1;
    q.push(r);
    num[r]=cnt;
    cnt++;
    while(!q.empty()){
        int qnum=q.front();
        q.pop();
        for(int i=0;i<graph[qnum].size();i++){
            if(visited[graph[qnum][i]]==0){
                visited[graph[qnum][i]]=1;
                q.push(graph[qnum][i]);
                num[graph[qnum][i]]=cnt;
                cnt++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,R,u,v;
    cin>>N>>M>>R;
    for(int i=1;i<=M;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }                      
    for(int i=1;i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    // for(int i=1;i<=M;i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<"\n";
    //     }
    // }
    bfs(N,M,R);
    for(int i=1;i<=N;i++){
        cout<<num[i]<<"\n";
    }
}