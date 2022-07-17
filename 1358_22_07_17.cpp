#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int W,H,X,Y,P,x,y,cnt=0;
    cin>>W>>H>>X>>Y>>P;
    int r=H/2,lcx=X,lcy=Y+r,rcx=X+W,rcy=Y+r; // 각 원의 중점 좌표
    for(int i=0;i<P;i++){
        cin>>x>>y;
        if(x>=X&&x<=X+W && y>=Y&&y<=Y+H)
            cnt++;
        else if(sqrt((x-X)*(x-X)+(y-(Y+r))*(y-(Y+r)))<=r||sqrt((x-(X+W))*(x-(X+W))+(y-(Y+r))*(y-(Y+r)))<=r)
            cnt++;
    }
    cout<<cnt;
}