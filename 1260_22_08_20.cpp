#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector <int> graph[1001];
queue <int> q;
int dfsvisitied[1001]={0},bfsvisitied[1001]={0},dcnt=1,bcnt=1;
int dfsans[1001]={0},bfsans[1001]={0};

void dfs(int s){
    dfsvisitied[s]=1;
    dfsans[dcnt]=s;
    dcnt++;
    for(int i=0;i<graph[s].size();i++){
        if(dfsvisitied[graph[s][i]]==0)
            dfs(graph[s][i]);
    }
}
void bfs(int s){
    bfsvisitied[s]=1;
    bfsans[bcnt]=s;
    bcnt++;
    q.push(s);
    while(!q.empty()){
        int qnum=q.front();
        q.pop();
        for(int i=0;i<graph[qnum].size();i++){
            if(bfsvisitied[graph[qnum][i]]==0){
                bfsvisitied[graph[qnum][i]]=1;
                q.push(graph[qnum][i]);
                bfsans[bcnt]=graph[qnum][i];
                bcnt++;
            }
        }
    }
}
int main(){
    int N,M,V,a,b;
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
        sort(graph[i].begin(),graph[i].end());
    dfs(V);
    bfs(V);
    for(int i=1;i<=dcnt-1;i++)
        cout<<dfsans[i]<<" ";
    cout<<"\n";    
    for(int i=1;i<=bcnt-1;i++)
        cout<<bfsans[i]<<" ";
}