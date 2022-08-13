// 처음에는 억지 기법을 이용하여 for문을 돌려서 해결해보려 하였다.
// 입력 값이 20억이 넘어가다보니 시간 초과는 당연한 결과였고 다른 방법을 찾아야 했다.
// 그래서 분할 정복 기법을 사용하려 했지만 피보나치 수열에 분할 정복 기법을 사용한 것과
// 다를 바가 없는 결과가 나와 계속 다른 방법을 찾아보았지만 실패했다.
// 그래서 구글링을 통해 힌트를 찾아 보았다. 힌트를 보고 풀어보려 했지만 그마저도 어려워서 시간이 많이 걸렸다.
// dp없이 한번 계산한 결과를 다시 부르지 않게 할 수 있는지에 대한 방법을 찾는 부분이 가장 어려웠다.
// 구글링을 통해 찾은 방법이 내가 생각지도 못했던 방법이라 신기했다.

// #include<iostream>
// using namespace std;
// int main(){
//     long long A,B,C,ans=1;
//     cin>>A>>B>>C;
//     for(int i=0;i<B;i++){
//         ans=ans*A%C;
//         cout<<ans<<"\n";
//     }
//     //cout<<ans<<"\n";
// }

#include<iostream>
using namespace std;

long long a,c;

long long recur(long long b){
    if(b==1) return a%c;
    long long num=recur(b/2);

    if(b%2==1)
        return ((num*num)%c*a)%c;
    else if(b%2==0)
        return (num*num)%c;
}

int main(){
    long long b;
    cin>>a>>b>>c;
    cout<<recur(b);
}

