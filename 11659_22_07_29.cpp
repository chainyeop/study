// #include<iostream> // 처음에는 입력받을때마다 계산하는 식으로 풀었는데 당연히 시간초과가 났다.
// using namespace std;
// int main(){
//     int N,M,i,j,sum=0,num,arr[100010]={0};
//     cin>>N>>M;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     for(int k=0;k<M;k++){
//         cin>>i>>j;
//         for(int a=i;a<=j;a++){
//             sum+=arr[a];
//         }
//         cout<<sum<<"\n";
//         sum=0;
//     }
// }

// #include<iostream> // 미리 합들을 구해 배열에 저장한 다음에 입력 받은 값에 맞는 배열의 값을 계산해 출력한다.
// using namespace std; // 처음에는 시간 초과가 떠서 당황했었는데 아래의 코드에 있는 cin, cout을 최적화 하는 구문을 추가하니 통과되었다.
// int main(){
//     int N,M,i,j,sum=0,num,arr[100010]={0};
//     cin>>N>>M;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     int psum[100010]={0};
//     psum[1]=arr[1];
//     for(int i=2;i<=N;i++){
//         psum[i]=psum[i-1]+arr[i];
//     }
//     for(int k=0;k<M;k++){
//         cin>>i>>j;
//         sum=psum[j]-psum[i-1];
//         cout<<sum<<"\n";
//         sum=0;
//     }
// }

#include<iostream> // 입력을 받자마자 바로바로 계산을 하게 만들었다.
using namespace std; // 위의 코드와 비교해 메모리와 시간이 더 줄어든 것을 확인할 수 있었다.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,i,j,sum=0,num,psum[100010]={0};
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>num;
        psum[i]=psum[i-1]+num;
        cout<<psum[i]<<"\n";
    }

    for(int k=0;k<M;k++){
        cin>>i>>j;
        sum=psum[j]-psum[i-1];
        cout<<sum<<"\n";
        sum=0;
    }
}