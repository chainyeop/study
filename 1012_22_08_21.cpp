// 이미 풀었던 백준 2667 문제와 거의 유사한 문제여서 쉽게 해결할 수 있을거라 생각했다.
// 그런데 자꾸 오류가 나서 원인을 찾아보니 테스트 케이스가 여러개라는 점을 간과했었다.
// 그래서 각 배열을 입력 받기 전에 각 배열을 0으로 초기화를 시켜주니 통과할 수 있었다.

#include<iostream>
#include<vector>
using namespace std;

int field[51][51];
int visited[51][51],cnt,count,M,N;

void dfs(int x,int y,int ax,int ay){
    if(field[x][y]==0||visited[x][y]==1) return;
    else{
        cnt++;
        visited[x][y]=1;
        int r=y+1; // 오른쪽 방향
        if(field[x][r]==1)
            dfs(x,r,ax,ay);
        int u=x-1; // 위쪽 방향
        if(field[u][y]==1)
            dfs(u,y,ax,ay);
        int l=y-1; // 왼쪽 방향
        if(field[x][l]==1)
            dfs(x,l,ax,ay);
        int d=x+1; // 아래쪽 방향
        if(field[d][y]==1)
            dfs(d,y,ax,ay);
    }
    if(x==ax && y==ay)
        count++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T,K,a,b;
    cin>>T;
    for(int i=0;i<T;i++){
        count=0;
        cin>>M>>N>>K;
        for(int k=0;k<M;k++){ // field배열 초기화
            for(int l=0;l<N;l++){
                field[k][l]=0;
            }
        }
        for(int k=0;k<M;k++){ // visitied배열 초기화
            for(int l=0;l<N;l++){
                visited[k][l]=0;
            }
        }        
        for(int j=0;j<K;j++){
            cin>>a>>b;
            field[a][b]=1;
        }
        for(int x=0;x<M;x++){
            for(int y=0;y<N;y++){
                cnt=0;
                dfs(x,y,x,y);
            }
        }
        for(int x=0;x<M;x++){
            for(int y=0;y<N;y++){
                cout<<field[x][y]<<" ";
            }
            cout<<"\n";
        } 
        for(int x=0;x<M;x++){
            for(int y=0;y<N;y++){
                cout<<visited[x][y]<<" ";
            }
            cout<<"\n";
        }       
        cout<<count<<"\n";
    }
}