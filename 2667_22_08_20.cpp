// 시간은 조금 걸렸지만 혼자서 해결할 수 있었다. 
// 단지수와 총 집의 수를 출력하는 부분에서 막혔었는데 함수의 인자를 줄 때 i, j를 두 개씩 줘서 해결했다.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[26][26]={0};
int visitied[26][26]={0},N,Count=0,cnt;
vector <int> answer;

void dfs(int x,int y,int ax,int ay){
    if(x<0||x>N) return; // 배열 범위를 넘어갈 경우 종료
    if(y<0||y>N) return;
    if(map[x][y]==0||visitied[x][y]==1) return;
    else if(visitied[x][y]==0){ // 값이 1이면서 방문한 적이 없는 경우
        cnt++; // 시작위치 또한 1이기 때문에 +1을 해줌
        visitied[x][y]=1;
        int r=y+1; // 오른쪽 방향
        if(map[x][r]==1){
            dfs(x,r,ax,ay);
        }
        int u=x-1; // 위쪽 방향
        if(map[u][y]==1){
            dfs(u,y,ax,ay);
        }
        int l=y-1; // 왼쪽 방향
        if(map[x][l]==1){
            dfs(x,l,ax,ay);
        }
        int d=x+1; // 아래쪽 방향
        if(map[d][y]==1){
            dfs(d,y,ax,ay);
        }
    }
    if(x==ax&&y==ay){
        Count++;
        answer.push_back(cnt);
    }
}
int main(){
    string s;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>s;
        for(int j=1;j<=N;j++){
            map[i][j]=s[j-1]-'0';
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cnt=0;
            dfs(i,j,i,j);
        }
    }
    //dfs(1,2,1,2);
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         cout<<visitied[i][j];
    //     }
    //     cout<<"\n";
    // } 
    cout<<Count<<"\n";
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"\n";
    }
}