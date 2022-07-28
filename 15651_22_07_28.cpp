// 백준 15649에서 back_t함수에 for문 안에 있는 if문을 제거만 하면 바로 풀 수 있는 문제였다.
// 이 문제는 생각보다 쉽게 해결할 수 있었다.
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
        //if(used[i]==false){ // 제거한 if문
            sol.push_back(i);
            used[i]=true;
            back_t(n,m);
            sol.pop_back();
            used[i]=false;
        //}
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    back_t(N,M);
}