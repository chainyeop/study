// 어떻게 풀지 고민하다 다른 사람들이 질문을 올려놓은 곳에 들어가 힌트를 찾아보았다.
// 그 중에 "가장 왼쪽에 있는 위치부터 순서대로 간격이 x이상이 되도록 공유기를 설치해 보면서 C개 이상을 설치할 수 있는지 확인해봐라."
// 라는 말이 있었고 이를 어떻게 구현할지 고민하다 우연히 구현에 성공했는데 바로 통과가 되었다. 
// 통과하고보니 이것만큼 확실한 방법이 없었던 것 같다.

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,C,num,home[200000]={0},Max=0;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>num;
        home[i]=num;
    }
    sort(home,home+N);
    long long start=1,end=home[N-1],mid;
    while(start<=end){
        int cnt=1,now=0;
        mid=(start+end)/2;
        for(int i=1;i<N;i++){ // 힌트에 나온 부분이다. 이 부분을 구현에 성공하니 나머지는 쉬웠다.
            if(home[i]-home[now]>=mid){
                cnt++;
                now=i;
            }
        }
        if(cnt>=C){
            start=mid+1;
            if(Max<mid) Max=mid;
        }
        else end=mid-1;
    }
    cout<<Max;
}