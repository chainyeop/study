#include<iostream>
using namespace std;

int recur(int n){
    if(n==1) return 1;
    return n*recur(n-1);
}

int main(){
    int N,K;
    cin>>N>>K;
    if(K==1)
        cout<<N;
    else if(K==0)
        cout<<1;
    else if(N==K)
        cout<<1;
    else {
        cout<<recur(N)/(recur(K)*recur(N-K));
    }
}