// 지난번에 풀었던 백준 7576문제를 3차원 배열로 푸는 문제였다. 
// 3차원 배열을 어떻게 구현할까 고민하다가 tuple을 이용하여 문제를 풀게 되었다.
// pair대신 tuple을 사용하는것 말고는 지난번에 푼 코드랑 거의 유사했다.
// 다만 작성 중에 bfs함수 안에 queue의 원소를 제거해주는 코드인 q.pop(); 코드를 미쳐 안적어서 출력이 되지 않았었다.
// 이를 모르고 tuple의 문제라고 착각해 삽질을 하다가 겨우 빠진 부분을 발견할 수 있었다. 

#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int field[101][101][101]={0},zero=0;
int answer[101][101][101]={0};
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}}; // 오, 왼, 앞, 뒤, 위, 아래
queue <tuple<int,int,int>> q;

void bfs(int m,int n,int h){
    while(!q.empty()){
        int qz=get<0>(q.front());
        int qx=get<1>(q.front());
        int qy=get<2>(q.front());
        q.pop();
        for(int i=0;i<6;i++){
            int qx_dir=qx+dir[i][1]; 
            int qy_dir=qy+dir[i][2];
            int qz_dir=qz+dir[i][0];
            if(qz_dir>=1&&qz_dir<=h && qx_dir>=1&&qx_dir<=n && qy_dir>=1&&qy_dir<=m){
                if(field[qz_dir][qx_dir][qy_dir]==0){
                    field[qz_dir][qx_dir][qy_dir]=1;
                    answer[qz_dir][qx_dir][qy_dir]=answer[qz][qx][qy]+1;
                    q.push(make_tuple(qz_dir,qx_dir,qy_dir));
                }
            }
        }
    }
}
int main(){
    int M,N,H,num,zero=0,ans=0;
    cin>>M>>N>>H;
    for(int k=1;k<=H;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>num;
                field[k][i][j]=num;
                if(field[k][i][j]==0) zero++;
                else if(field[k][i][j]==1){
                    q.push(make_tuple(k,i,j));
                }
            }
        }
    }
    if(zero==0){
        cout<<"0"<<"\n";
        return 0;
    }
    bfs(M,N,H);
    for(int k=1;k<=H;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(field[k][i][j]==0){
                    cout<<"-1"<<"\n";
                    return 0;
                }
                if(ans<answer[k][i][j])
                    ans=answer[k][i][j];
            }
        }
    }
    cout<<ans;
}