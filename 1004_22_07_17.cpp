#include<iostream> // 
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,startx,starty,endx,endy,cx,cy,r,cnt=0;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>startx>>starty>>endx>>endy;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>cx>>cy>>r;
            if(sqrt((startx-cx)*(startx-cx)+(starty-cy)*(starty-cy))<=r && sqrt((endx-cx)*(endx-cx)+(endy-cy)*(endy-cy))<=r)
                continue;
            if(sqrt((startx-cx)*(startx-cx)+(starty-cy)*(starty-cy))<=r)
                cnt++;
            else if(sqrt((endx-cx)*(endx-cx)+(endy-cy)*(endy-cy))<=r)
                cnt++;
        }
        cout<<cnt<<"\n";
        cnt=0;
    }
}