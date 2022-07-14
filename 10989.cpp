#include<iostream>
using namespace std;
int main(){
    int N,num;
    int arr[10001]={0};
    int cnt[10001]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        cnt[num]++;
    }
    //int count=0;
    for(int i=1;i<=10000;i++){
        if(cnt[i]>0){
            for(int j=0;j<cnt[i];j++){
                // arr[count]=i;
                // count++;
                cout<<i<<"\n";
            }        
        }
    }
    // for(int i=0;i<N;i++){
    //     cout<<arr[i]<<"\n";
    // }
}