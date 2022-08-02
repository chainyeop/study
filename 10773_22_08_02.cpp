#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K,num,sum=0;
    vector <int> v;
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>num;
        if(num==0)
            v.pop_back();
        else
            v.push_back(num);
    }
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    cout<<sum;
}