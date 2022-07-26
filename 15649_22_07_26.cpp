// 3-1학기에 사용했던 알고리즘 책에 나온 파이썬 백트래킹 코드를 활용했다.
#include<iostream>
#include<vector>
using namespace std;

vector <int> sol;
bool used[9]={false};

void back_t(int n, int m){
    if(m==sol.size()){
        for(int j=0;j<m;j++){
            cout<<sol[j]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(used[i]==false){
            sol.push_back(i);
            used[i]=true;
            back_t(n,m);
            sol.pop_back();
            used[i]=false;
        }
    }    
}
int main(){
    int N,M;
    cin>>N>>M;
    back_t(N,M);
}


// #include<iostream>
// #include<vector>
// using namespace std;

// vector <int> a;

// void v(int n){
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<"\n";
//     }
//     return;
// }

// int main(){
//     int N,num;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>num;
//         a.push_back(num);
//     }
//     for(int i=0;i<N;i++){
//         cout<<a[i]<<" ";
//     }
//     v(N);
// }