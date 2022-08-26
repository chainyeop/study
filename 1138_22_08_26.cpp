// 스스로 어떻게든 해결해 보려다 결국 구글링을 통해 해결하였다.
// 나중에 내가 적던 코드로 다시 해결해보려 했지만 결국 내가 풀던 것으로는 풀지 못했다.

#include<iostream>
using namespace std;
int main(){
    int N,num,arr[10]={0},ans[10]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr[i]=num;
    }
    for(int i=0;i<N;i++){
        if(i==0)
            ans[arr[i]]=i+1;
        else if(i>0){
            for(int j=0;j<N;j++){
                if(arr[i]==0&&ans[j]==0){
                    ans[j]=i+1;
                    break;
                }
                else if(ans[j]==0){
                    arr[i]-=1;
                }
            }
        }  
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<" ";
    }
}


