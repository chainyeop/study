#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    int N;
    string str,a;
    queue <int> q;
    cin>>N;
    cin.ignore(256,'\n'); 
    for(int i=0;i<N;i++){
        getline(cin,str);
        if(str=="pop"){
            if(q.empty())
                cout<<"-1"<<"\n";
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(str=="size"){
            cout<<q.size()<<"\n";
        }
        else if(str=="empty"){
            if(q.empty())
                cout<<"1"<<"\n";
            else
                cout<<"0"<<"\n";
        }
        else if(str=="front"){
            if(q.empty())
                cout<<"-1"<<"\n";
            else
                cout<<q.front()<<"\n";
        }
        else if(str=="back"){
            if(q.empty())
                cout<<"-1"<<"\n";
            else
                cout<<q.back()<<"\n";
        }
        else{
            for(int j=0;j<str.size();j++){
                if(str[j]>='0' && str[j]<='9'){
                    a.push_back(str[j]);
                }
            }
            q.push(stoi(a));
            a.clear();
        }
    }
}