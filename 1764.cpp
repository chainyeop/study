#include<iostream>
#include<set>
using namespace std;
int main(){
    int N,M;
    string str;
    set <string> nohear;
    set <string> nohearsee;
    set<string>::iterator iter;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>str;
        nohear.insert(str);
    }
    for(int i=0;i<M;i++){
        cin>>str;
        if(nohear.find(str)!=nohear.end())
            nohearsee.insert(str);
    }
    cout<<nohearsee.size()<<endl;
    for(iter = nohearsee.begin();iter != nohearsee.end();iter++){
        cout<<*iter<<endl;
    }
}