// 구글링을 통해 약간의 힌트를 얻어 해결하였다.
// 15650번 문제를 풀 때 함수에 인자를 하나 더 추가해서 해결했던 방식을 15651번에 적용하는 방식으로 풀었다.
// 인자로 i를 넘겨 주는데 이렇게 하면 15650번의 결과에서 1 1, 2 2 등 중복되는 숫자들이 추가되는 것을 확인할 수 있었다.
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
        sol.push_back(i);
        used[i] = true;
        back_t(n, m,i); // 함수에 인자를 추가 하는데 i+1가 아니라 i를 넘겨준다.
        sol.pop_back();
        used[i] = false;
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    back_t(N,M,1);
}