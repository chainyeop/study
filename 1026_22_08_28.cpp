#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,num,Aarr[50]={0},Barr[50]={0},sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        Aarr[i]=num;
    }
    for(int i=0;i<N;i++){
        cin>>num;
        Barr[i]=num;
    }
    sort(Aarr,Aarr+N);
    sort(Barr,Barr+N,greater<int>());
    for(int i=0;i<N;i++){
        sum=sum+Aarr[i]*Barr[i];
    }
    cout<<sum;
}