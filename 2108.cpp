#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int N,num,arr[5000]={0},arr1[8001]={0},cnt[8001]={0},value=0;
    double sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr[i]=num;
        sum+=num;
        cnt[num+4000]++;
    }
    sort(arr,arr+N);
    int max=0;
    for(int i=0;i<8001;i++){ // 가장 많이 나온 수의 개수를 max값에 저장
        if(cnt[i]>max){
            max=cnt[i];
        }
    }
    for(int i=0;i<8001;i++){
        if(cnt[i]==max){ // max값을 가진 모든 수를 arr1배열에 저장
            arr1[value]=i-4000;
            value++;
        }
    }
    sort(arr1,arr1+value);
    if(sum/N>-0.5 && sum/N<0)
        cout<<round(sum/N + 0.5)<<endl;
    else
        cout<< round(sum/N)<<endl;
    cout<< arr[N/2]<<endl;
    if(value==1)
        cout<< arr1[0]<<endl;
    else
        cout<< arr1[1]<<endl;
    cout<< arr[N-1]-arr[0];
}