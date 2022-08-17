// 처음에는 무한루프 문제가 발생하여 이를 해결하느라 조금 애를 먹었다.
// 알고보니 start와 end값에 mid값을 넣어줄 때 1을 빼거나 더하지 않아서 발생했던 문제였다.
// 그리고 cnt가 N보다 클 경우에도 답이 될수 있다는 것을 간과하여 Max의 값을 바꿔주는 코드를 안 넣었더니 틀렸다고 나왔다.

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int K,N,num,arr[10000]={0},Max=0;
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>num;
        arr[i]=num;
    }
    sort(arr,arr+K);
    long long start=1,end=arr[K-1],mid,check=0;
    while(start<=end){
        int cnt=0;
        mid=(start+end)/2;
        for(int i=0;i<K;i++){ // 만들수 있는 랜선의 개수 구하기
            int a=arr[i]/mid;
            cnt+=a;
        }
        if(cnt==N){ // 만들어야 하는 랜선의 개수와 같을 때
            start=mid+1;
            //end=arr[K-1];
            if(Max<mid) Max=mid;
        }
        else if(cnt>N){ // 만들어야 하는 랜선의 개수보다 많을 때
            start=mid+1;
            if(Max<mid) Max=mid;
        }
        else if(cnt<N) // 만들어야 하는 랜선의 개수보다 적을 때
            end=mid-1;
    }    
    cout<<Max<<"\n";
}