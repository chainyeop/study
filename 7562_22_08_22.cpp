// 테이트 케이스가 여러개여서 memset을 이용하여 bfs함수를 호출할 때마다 배열을 초기화해주었다.

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int visited[301][301]={0},cnt=0;
int chess[301][301]={0};
int dir[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}}; // 우측 상단부터 시계방향
queue <pair<int,int>> q;

void bfs(int I,int sx,int sy,int ex,int ey){
    visited[sx][sy]=1;
    q.push(make_pair(sx,sy));
    chess[sx][sy]=0;
    while(!q.empty()){
        int qx=q.front().first;
        int qy=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int qx_dir=qx+dir[i][0]; 
            int qy_dir=qy+dir[i][1];
            if(qx_dir>=0&&qx_dir<=I-1 && qy_dir>=0&&qy_dir<=I-1){
                if(visited[qx_dir][qy_dir]==0){
                    visited[qx_dir][qy_dir]=1;
                    chess[qx_dir][qy_dir]=chess[qx][qy]+1;
                    q.push(make_pair(qx_dir,qy_dir));
                }
            }
            if(qx_dir==ex && qy_dir==ey)
                return;
        }
    }
}
int main(){
    int T,I,num,sx,sy,ex,ey;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>I;
        cin>>sx>>sy;
        cin>>ex>>ey;
        memset(visited,0,sizeof(visited)); // 배열을 0으로 초기화 함
        memset(chess,0,sizeof(chess));
        bfs(I,sx,sy,ex,ey);
        cout<<chess[ex][ey]<<"\n";
    }
}

