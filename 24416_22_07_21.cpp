#include<iostream> // 쉬운 문제 였는데 함수 호출 횟수라는 말에 걸려서 해결하는데 생각보다 오래걸렸다.
using namespace std; // dp의 경우 n에서 2를 빼면 되고 재귀의 경우 함수 호출 횟수를 어떻게 새야하나 하는 고민을 했었는데
int f[41]={0};       // 그럴필요 없이 n번째 피보나치수열의 수를 반환하면 끝나는 문제여서 허탈했다.
fib1(int n){
    if(n==1 || n==2) return 1;
    return fib1(n-1)+fib1(n-2);
}

fib2(int n){
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fib1(n)<<" "<<n-2; 
}