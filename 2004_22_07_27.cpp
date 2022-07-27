// #include<iostream> // 백준 1676을 풀 때 사용했던 방법으로 풀려고 했으나 입력값이 최대 20억이어서 다른 방법을 생각해야 했다.
// using namespace std; // 아래와 같은 방법으로는 시간초과 때문에 해결이 안된다.

// int count(int num,int m){
//     int cnt=0;
//     for(int i=1;i<=num;i++){
//         int a=i;
//         while(a>=5){
//             if(a%5==0)
//                 cnt++;
//             else 
//                 break;
//             a=a/5;
//         }
//     }
//     return cnt;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     if(m==0||n==1){
//         cout<<"0";
//         return 0;
//     }
//     cout<<count(n)-count(m)-count(n-m);
// }

// 그래서 구글링을 통해 다른 방법을 찾았고 그 방법을 통해서 해결을 할 수 있었다.
// 처음에는 5의 배수의 개수만을 구하면 된다고 생각해서 풀었다.
// 어짜피 2의 배수의 개수가 5의 배수의 개수보다 많을수 밖에 없다고 생각했기 때문이다.
// 그런데 그렇게 제출하니 틀렸다고 나와서 당황스러웠다. 왜 2의 배수의 개수까지 세줘야 하는지 이해하는데 시간이 오래 걸렸다.

#include<iostream>
using namespace std;

int count(long long num){
    int cnt=0;
    while(num>=5){
        cnt+=num/5;
        num/=5;
    }
    return cnt;
}

int count2(long long num){
    int cnt=0;
    while(num>=2){
        cnt+=num/2;
        num/=2;
    }
    return cnt;
}

int main(){
    long long n,m;
    int a,b;
    cin>>n>>m;
    a=count(n)-count(m)-count(n-m);
    b=count2(n)-count2(m)-count2(n-m);
    cout<<min(a,b);
}