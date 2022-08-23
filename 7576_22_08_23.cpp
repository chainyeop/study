// 시작 위치가 여러군대일수 있어서 어떻게 풀지 막막했었다.
// 그런데 상관없이 bfs로 똑같이 풀면 되는 문제였다.
// 그전의 bfs들이랑 차이점은 큐에 미리 시작지점들을 넣어놓고 시작한다는 것이다. 
// 그리고 bfs호출시 바로 while문으로 들어가는 것도 차이점이다.

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int field[1001][1001]={0};
int answer[1001][1001]={0};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; // 오, 아래, 왼, 위
queue <pair<int,int>> q;

void bfs(int n,int m){
    while(!q.empty()){
        int qx=q.front().first;
        int qy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int qx_dir=qx+dir[i][0]; 
            int qy_dir=qy+dir[i][1];
            if(qx_dir>=1&&qx_dir<=n && qy_dir>=1&&qy_dir<=m){
                if(field[qx_dir][qy_dir]==0){
                    answer[qx_dir][qy_dir]=answer[qx][qy]+1;
                    field[qx_dir][qy_dir]=1; 
                    q.push(make_pair(qx_dir,qy_dir));
                }
            }
        }
    }
}
int main(){
    int M,N,num,zero=0,one=0,ans=0;
    cin>>M>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>num;
            field[i][j]=num;
            if(num==0) zero++; // 0의 개수를 세어줌
            else if(field[i][j]==1)
                q.push(make_pair(i,j));
        }
    }
    if(zero==0){ // 이미 모든 토마토가 익어있는 상태일 경우
        cout<<"0";
        return 0;
    }
    bfs(N,M);
    zero=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(field[i][j]==0)
                zero++;
            if(answer[i][j]>ans)
                ans=answer[i][j];
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         cout<<answer[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(zero>0) cout<<"-1"; // 토마토가 모두 익지 못하는 경우
    else cout<<ans;
}