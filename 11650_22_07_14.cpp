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
        arr.push_back(pair<int,int> (a,b));
    }
    sort(arr.begin(),arr.end());
    for(iter=arr.begin();iter!=arr.end();iter++){
        cout<<iter->first<<" "<<iter->second<<"\n";
    }
}