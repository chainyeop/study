// #include<iostream> // 당연히 일단 시간초과가 날것으로 예상하고 코드를 작성했다. 예상대로 시간초과가 떴다.
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     int N,num,check=0,number;
//     vector <int> v;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>num;
//         v.push_back(num);
//     }
//     sort(v.begin(),v.end());
//     for(int i=2;i<V[N];i++){
//         check=0;
//         int a=v[0]%i;
//         for(int j=1;j<N;j++){
//             if(v[j]%i==a)
//                 continue;
//             else{
//                 check=1;
//                 break;
//             }
//         }
//         if(check==0)
//             cout<<i<<"\n";
//     }
// }

// 도저히 해결이 되지 않아 구글링 끝에 공식을 사용해야 한다는 것을 발견했다.
// 그 후 공식을 이용해 코드를 작성했음에도 해결이 되지 않았다.
// N의 수가 2일 경우 gcd=a; 라는 코드가 제대로 작동하지 않는다는 것을 발견 후 위치를 옮겨 해결할 수 있었다.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int N,num,count=0,number,r,gcd;
    vector <int> v;
    vector <int> g;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int a=v[1]-v[0];
    for(int i=2;i<N;i++){ // v벡터에서 v[i]-v[i-1]들의 최대 공약수를 구하는 코드
        int b=v[i]-v[i-1];
        if(b>a){
            while (a != 0){
                r = b % a;
                b = a;
                a = r;
            }
            a=b;            
        }
        else if(a>b){
            while (b != 0){
                r = a % b;
                a = b;
                b = r;
            }
        }
        //gcd=a; 원래 있었던 위치
    }
    gcd=a;
    for(int i=1;i<=sqrt(gcd);i++){
        if(gcd%i==0){
            g.push_back(i);
            if(i!=gcd/i)
                g.push_back(gcd/i);
        }
    }
    sort(g.begin(),g.end());
    for(int i=1;i<g.size();i++){
        cout<<g[i]<<" ";
    } 
}

