#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int arr[64][64]={0};

void quadtree(int x,int y,int n){
    int one=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(arr[i][j]==1)
                one++;
        }
    }
    if(one==pow(n,2)) cout<<"1";
    else if(one==0) cout<<"0";
    else{
        cout<<"(";
        quadtree(x,y,n/2);
        quadtree(x,y+n/2,n/2);
        quadtree(x+n/2,y,n/2);
        quadtree(x+n/2,y+n/2,n/2);
        cout<<")";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    string s;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<N;j++){
            //int a=stoi(s[j]);
            arr[i][j]=s[j]-'0';
        }
    }
    quadtree(0,0,N);
}