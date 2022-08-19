#include<iostream>
using namespace std;

int odp[41]={0};
int zdp[41]={0};

int zfibo(int n){
    if(zdp[n]!=0) return zdp[n];
    if(n==0) return 1;  
    else if(n==1) return 0;
    else
        zdp[n]=zfibo(n-1)+zfibo(n-2);
    return zdp[n];
}

int ofibo(int n){
    if(odp[n]!=0) return odp[n];

    if(n==0) return 0;
    else if(n==1) return 1;
    else 
        odp[n]=ofibo(n-1)+ofibo(n-2);
    return odp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<zfibo(N)<<" "<<ofibo(N)<<"\n";
    }
}