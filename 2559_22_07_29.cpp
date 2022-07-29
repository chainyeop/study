// #include<iostream> // set을 이용하여 풀었던 코드이다.
// #include<set>      // set에 원소를 넣으면 자동으로 정렬이 되니 마지막 원소만 출력해주면 된다는 생각에서였다.
// using namespace std;
// int main(){
//     int N,K,num,sum=0,arr[100010]={0};
//     set <int> s;
//     set <int>::reverse_iterator riter; // 구글링 도중 reverse_iterator라는 것의 사용법에 대해서 알게 되었다.
//     cin>>N>>K;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     for(int i=1;i<=K;i++){
//         sum+=arr[i];
//     }
//     s.insert(sum);
//     for(int j=K+1;j<=N;j++){
//         sum=sum+arr[j]-arr[j-K];
//         s.insert(sum);
//     }
//     riter=s.rbegin(); // rbegin()을 이용하여 마지막 원소를 바로 출력할 수 있다.
//     cout<<*riter;
// }
//146

#include<iostream> // vector를 이용하여 다시 풀어보았는데 28ms가 나왔고 set보다 4ms 더 빨랐다.
#include<vector>   
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false); // cin, cout 최적화 코드를 넣어주었더니 12ms가 나왔다.
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K,num,sum=0,arr[100010]={0};
    vector <int> v;   
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>num;
        arr[i]=num;
    }
    for(int i=1;i<=K;i++){
        sum+=arr[i];
    }
    v.push_back(sum);
    for(int j=K+1;j<=N;j++){
        sum=sum+arr[j]-arr[j-K];
        v.push_back(sum);
    }
    sort(v.begin(),v.end());
    cout<<v.back();
}