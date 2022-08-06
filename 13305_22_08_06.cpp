// 풀다가 감을 못잡아서 구글링을 통해 힌트를 얻어 문제를 해결하였다.
// 보고나니 생각보다 쉬운 문제여서 허탈했다.

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int N,num,now;
    long long s[100000]={0},l[100000]={0},sum=0;
    cin>>N;
    for(int i=0;i<N-1;i++){
        cin>>num;
        l[i]=num;
    }
    for(int i=0;i<N;i++){
        cin>>num;
        s[i]=num;
    }
    now=s[0];
    sum=s[0]*l[0];
    for(int i=1;i<N;i++){
        if (now<s[i])
            sum = sum + now * l[i];
        else{
            now=s[i];
            sum = sum + now * l[i];
        }
    }
    cout<<sum;
}