// #include<iostream> // 팩토리얼 계산에 dp를 이용하면 될거라 생각했지만 나의 착각이었다.
// using namespace std; // 이런 방식으로 하면 문제를 해결할 수 없었다.
                        // 바로 전에 푼 문제였던 백준 11050에 썼던 코드를 그래도 활용했지만 결과적으로는 실패였다.
// int arr[1001]={0};

// int recur(int n){
//     if(arr[n]!=0) return arr[n];
//     if(n==1) return 1;
//     else
//         arr[n]=n*recur(n-1);
//     return arr[n]%10007;
// }

// int main(){
//     int N,K;
//     cin>>N>>K;
//     if(K==1)
//         cout<<N;
//     else if(K==0 || N==K)
//         cout<<1;
//     else 
//         cout<<(recur(N)/(recur(K)*recur(N-K)));
// }

#include<iostream> // 파스칼 삼각형을 활용하여 이중배열에 dp를 적용했다.
using namespace std; // 이렇게 하니 훨씬 쉽게 문제를 해결할 수 있었다.

int arr[1001][1001]={0};

int recur(int n,int k){
    if(arr[n][k]!=0) return arr[n][k];
    if(k==0) return 1;
    else if(k==n) return 1;
    else
        arr[n][k]=recur(n-1,k-1)+recur(n-1,k);

    return arr[n][k]%10007;
}

int main(){
    int N,K;
    cin>>N>>K;
    if(K==1) cout<<N;
    else if(K==0 || N==K) cout<<1;
    else 
        cout<<recur(N,K);
}
