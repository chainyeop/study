#include<iostream>
using namespace std;

long long k[101]={0};

long long P(int n){
    if(k[n]!=0) return k[n];
    if(n<=3) return 1;
    else
        k[n]=P(n-2)+P(n-3);
    return k[n];    
}

int main(){
    int T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<P(N)<<"\n";
    }
}