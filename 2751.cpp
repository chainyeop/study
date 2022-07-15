// vector와 pair를 이용한 문제
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N;
    int arr[1000]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<"\n";
    }
}