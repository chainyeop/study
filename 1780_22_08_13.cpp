#include<iostream>
#include<cmath>
using namespace std;

int arr[2187][2187]={0},mone=0,zero=0,one=0;

void recur(int x,int y,int n){
    int z=0,o=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(arr[i][j]==1) o++;
            else if(arr[i][j]==0) z++;
        }
    }
    if(o==pow(n,2)) one++;
    else if(z==pow(n,2)) zero++;
    else if(o==0 && z==0) mone++;
    else{
        recur(x,y,n/3); // 0,0
        recur(x,y+n/3,n/3); // 0,1
        recur(x,y+2*n/3,n/3); // 0,2
        recur(x+n/3,y,n/3); // 1,0
        recur(x+n/3,y+n/3,n/3); // 1,1
        recur(x+n/3,y+2*n/3,n/3); // 1,2
        recur(x+2*n/3,y,n/3); // 2,0
        recur(x+2*n/3,y+n/3,n/3); // 2,1
        recur(x+2*n/3,y+2*n/3,n/3); // 2,2
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
    cout<<mone<<"\n"<<zero<<"\n"<<one;
}