#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,a,b;
    vector <pair<int,int>> v;
    vector <pair<int,int>>::iterator iter;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        v.push_back(pair<int,int>(b,a)); // 입력하는 위치만 바꿔줌
    }
    sort(v.begin(),v.end());
    for(iter=v.begin();iter!=v.end();iter++){
        cout<<iter->second<<" "<<iter->first<<"\n";
    }
}