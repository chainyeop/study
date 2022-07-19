#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,num;
    cin>>N;
    vector <int> v;
    vector <int> findv;
    for(int i=0;i<N;i++){
        cin>>num;
        v.push_back(num);
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>num;
        findv.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<M;i++){
        int start=0,end=N-1,mid,check=0;
        while(start<=end){
            mid=(start+end)/2;
            if(findv[i]==v[mid]){
                check=1;
                break;
            }
            else if(findv[i]<v[mid])
                end=mid-1;
            else if(findv[i]>v[mid])
                start=mid+1;
        }
        if(check==1)
            cout<<"1"<<"\n";
        else
            cout<<"0"<<"\n";
    }
}