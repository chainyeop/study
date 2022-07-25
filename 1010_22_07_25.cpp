#include<iostream> // 백준 11051을 해결할 때 사용했던 파스칼 삼각형을 이용하였다.
using namespace std; // 이 문제도 조합 문제여서 똑같이 적용히 가능했다.

int arr[30][30]={0};

int func(int n, int m){
    if (arr[n][m] != 0) return arr[n][m];
    if (m == 0) return 1;
    else if (m == n) return 1;
    else
        arr[n][m] = func(n - 1, m - 1) + func(n - 1, m);

    return arr[n][m];
}

int main(){
    int T,N,M;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N>>M;
        if(N==1)
            cout<<M<<"\n";
        else if(N==M)
            cout<<1<<"\n";
        else
            cout<<func(M,N)<<"\n";
    }
}

