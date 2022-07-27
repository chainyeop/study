// 저번에 했던 코드를 바탕으로 하여 쉽게 해결할 수 있을줄 알았는데 굉장히 어렵게 풀었다.
// 구글링을 통해 힌트를 얻어서 시도해 보았지만 스스로 해결하는데는 실패했다.
// 함수에 변수 하나를 더 추가하는 방식이었는데 어떻게 동작하는지 이해하는데 굉장히 오랜 시간이 걸렸다.
#include<iostream>
#include<vector>
using namespace std;

vector <int> sol;
bool used[9]={false};

void back_t(int n, int m,int num){
    if(m==sol.size()){
        for(int j=0;j<m;j++){
            cout<<sol[j]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=num;i<=n;i++){
        if(used[i]==false){
            sol.push_back(i);
            used[i]=true;
            back_t(n,m,i+1); // 이 재귀 함수가 어떻게 해서 동작하는지 이해하는데 어려움을 겪었다.
            sol.pop_back();
            used[i]=false;
        }
    }    
}
int main(){
    int N,M;
    cin>>N>>M;
    back_t(N,M,1);
}