#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,num,arr[10000]={0},Max;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num;
        arr[i]=num;
    }
    sort(arr,arr+N);
    long long start=0,end=arr[N-1],mid;
    while(start<=end){
        long long sum=0;
        mid=(start+end)/2;
        for(int i=0;i<N;i++){
            if(mid<arr[i]){
                int a=arr[i]-mid;
                sum+=a;
            }
        }
        if(sum>=M){
            start=mid+1;
            if(Max<mid) Max=mid;
        }
        else end=mid-1;
    }
    cout<<Max;
}