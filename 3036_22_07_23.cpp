#include<iostream>
using namespace std;

int gcd(int a, int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,r[100]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>r[i];
    }
    for(int i=1;i<N;i++){
        int result=gcd(r[0],r[i]);
        cout<<r[0]/result<<"/"<<r[i]/result<<"\n";
    }
}