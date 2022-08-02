#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K,num,arr[10],cnt=0;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>num;
        arr[i]=num;
    }
    // for(int i=N-1;i>=0;i--){
    //     if(K>=arr[i]){
    //         int a=K/arr[i];
    //         cnt+=a;
    //         K-=a*arr[i];
    //     }
    // }
    int i=N-1;
    while(K!=0){
        if (K >= arr[i]){
            int a = K / arr[i];
            cnt += a;
            K -= a * arr[i];
        }
        i--;
    }
    cout<<cnt;
}   