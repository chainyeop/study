// 3중 반복문을 이용하면 쉽게 풀수 있는 문제였다.
// 하지만 너무 어렵게 생각한 나머지 문제를 해결하는데 정말 시간을 많이 잡아먹었다.
// 심지어 저번 학기에 썼던 교재에도 나와있던 문제였다.
// 쉬운 길을 두고 너무 돌아가서 시간을 낭비하였다.
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K,num,A[100][100]={0},B[100][100]={0};
    int ans=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>num;
            A[i][j]=num;
        }
    }
    cin>>M>>K;
    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
            cin>>num;
            B[i][j]=num;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            ans=0;
            for(int k=0;k<M;k++){
                ans+=A[i][k]*B[k][j];
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}