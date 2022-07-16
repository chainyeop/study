#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,age;
    string name;
    vector <pair<int,string>> member[200]; // vector 배열을 이용하여 해결
    vector <pair<int,string>>::iterator iter;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>age>>name;
        member[age-1].push_back(pair<int,string>(age,name));
    }
    for(int i=0;i<200;i++){ 
        if(member[i].size()>0){
            for(iter=member[i].begin();iter!=member[i].end();iter++){
                cout<<iter->first<<" "<<iter->second<<"\n"; 
            }
        }
    }
}