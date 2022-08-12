// 약간의 힌트를 통해 생각보다 손쉽게 해결할수 있었다.
// 사각형을 4개로 나누어 각각을 다시 재귀호출하는 식으로 문제를 해결했다.

#include<iostream>
#include<cmath>
using namespace std;

int white=0,blue=0,arr[128][128]={0};

void recur(int x, int y, int n){
    int b=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(arr[i][j]==1)
                b++;
        }
    }
    if(b==0) white++;
    else if(b==pow(n,2)) blue++;
    else{
        recur(x,y,n/2); // 왼쪽 위
        recur(x,y+n/2,n/2); // 오른쪽 위
        recur(x+n/2,y,n/2); // 왼쪽 아래
        recur(x+n/2,y+n/2,n/2); // 오른쪽 아래
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,num;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num;
            arr[i][j]=num;
        }
    }
    recur(0,0,N);
    cout<<white<<"\n"<<blue;
}