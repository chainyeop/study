// dfs가 더 편해서 이 문제로 dfs로 해결하려고 했지만 이 문제는 dfs로 풀면 시간초과가 뜬다고 해서 어쩔수 없이 bfs로 풀었다.
// 개인적으로 dfs보다 bfs가 더 어려워서 해결하는게 쉽지 않았다.
// 구글링을 통해 힌트를 얻어 문제를 해결하였다.
// answer배열 없이 해결해보기 위해 cnt변수 하나만을 사용했었는데 이걸로는 해결책을 찾지 못해 배열을 사용하여 문제를 해결했다.

#include<iostream>
#include<queue>
using namespace std;

int maze[101][101]={0};
int visited[101][101]={0},cnt=1;
int answer[101][101]={0};
queue <pair<int,int>> q;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; // 오, 아래, 왼, 위

void bfs(int n,int m){
    visited[1][1]=1;
    q.push(make_pair(1,1));
    answer[1][1]=cnt;
    while(!q.empty()){
        int qx=q.front().first;
        int qy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(qx+dir[i][0]>=1&&qx+dir[i][0]<=n && qy+dir[i][1]>=1&&qy+dir[i][1]<=m){ // 미로의 범위 안일 경우
                if(maze[qx+dir[i][0]][qy+dir[i][1]]==1&&visited[qx+dir[i][0]][qy+dir[i][1]]==0){
                    visited[qx+dir[i][0]][qy+dir[i][1]]=1;
                    answer[qx+dir[i][0]][qy+dir[i][1]]=answer[qx][qy]+1;
                    q.push(make_pair(qx+dir[i][0],qy+dir[i][1]));
                }
            }
        }
    }
}
int main(){
    int N,M;
    string s;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>s;
        for(int j=1;j<=s.size();j++){
            maze[i][j]=s[j-1]-'0';    
        }
    }
    bfs(N,M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<answer[N][M];
}