// 5!부터 나온 수를 그대로 이용하는 것이 아니라 0의 개수에 1을 더한만큼 10을 곱해서 그만큼을
// 나눈 나머지를 다음 값으로 이용했었다. 처음에는 이렇게 하면 될줄 알았는데 이렇게 해도 값이 커졌을 때
// 출력이 제대로 되지 않는 문제가 있었다.
// 결국 구글링을 통해서 방법을 찾아보았는데 굉장히 간단한 방법이여서 허탈했었다.
// #include<iostream>
// #include<string>
// using namespace std;

// long long arr[500]={0};

// long long fact(int n){
//     int cnt=0;
//     if(arr[n]!=0) return arr[n];
//     if(n==5) return 20;
//     else{
//         arr[n]=n*fact(n-1);
//         long long num=arr[n];
//         for(int i=0;;i++){
//             if(num%10==0){
//                 cnt++;
//                 num=num/10;
//             }
//             else 
//                 break;
//         }
//         int number=1;
//         for(int i=0;i<cnt+2;i++){
//             number*=10;
//         }
//         //int b=arr[n]/number;
//         arr[n]=arr[n]%number;
//     }
//     return arr[n];    
// }
// int main(){
//     int N,cnt=0;
//     string a;
//     cin>>N;
//     if(N<=4){
//         cout<<"0";
//         return 0;
//     }
//     int num=fact(N);
//     cout<<num<<"\n";
//     for(int i=0;i<N;i++){
//         if(num%10==0){
//             cnt++;
//             num=num/10;
//         }
//         else
//             break;
//     }
//     cout<<cnt;
// }

// N의 이하의 수에 5로 나누어지는 개수의 수가 0의 개수였다.
// 이런 방식은 생각도 못한 방식이어서 굉장히 신기했다.
#include<iostream>
using namespace std;
int main(){
    int N,cnt=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        if(i%125==0)
            cnt+=3;
        else if(i%25==0)
            cnt+=2;
        else if(i%5==0)
            cnt++;
    }
    cout<<cnt;
}