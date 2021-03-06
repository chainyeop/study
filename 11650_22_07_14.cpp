// vector와 pair를 이용한 문제
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N,a,b;
    cin>>N;
    vector <pair<int,int>> arr;
    vector <pair<int,int>>::iterator iter;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        arr.push_back(pair<int,int> (a,b)); // vector와 pair를 사용하니 굉장히 편리함
    }
    sort(arr.begin(),arr.end());
    for(iter=arr.begin();iter!=arr.end();iter++){
        cout<<iter->first<<" "<<iter->second<<"\n";
    }
}
