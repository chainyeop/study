#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,num,A[50]={0},P[50]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        A[i]=num;
        P[i]=num;
    }
    sort(A,A+N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(P[i]==A[j]){
                cout<<j<<" ";
                A[j]=0;
                break;
            }
        }
    }
}