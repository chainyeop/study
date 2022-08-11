// 마지막에 push_back 부분이 실행이 되지 않아 한참 애를 먹었다.
// string::npos을 이용하여 push_front가 아니라 push_back이 올 경우 string::npos를 반환하는 점을 이용하였다.

#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    int N;
    string str,a;
    deque <int> dq;
    cin>>N;
    cin.ignore(256,'\n'); 
    for(int i=0;i<N;i++){
        getline(cin,str);
        if(str=="pop_front"){
            if(dq.empty())
                cout<<"-1"<<"\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(str=="pop_back"){
            if(dq.empty())
                cout<<"-1"<<"\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
        else if(str=="size"){
            cout<<dq.size()<<"\n";
        }
        else if(str=="empty"){
            if(dq.empty())
                cout<<"1"<<"\n";
            else
                cout<<"0"<<"\n";
        }
        else if(str=="front"){
            if(dq.empty())
                cout<<"-1"<<"\n";
            else
                cout<<dq.front()<<"\n";
        }
        else if(str=="back"){
            if(dq.empty())
                cout<<"-1"<<"\n";
            else
                cout<<dq.back()<<"\n";
        }
        // else if(str=="push_front"){
            
        // }

        else{
            if(str.find("front")!=string::npos){
                for(int j=0;j<str.size();j++){
                    if(str[j]>='0' && str[j]<='9')
                        a.push_back(str[j]);
                }
                dq.push_front(stoi(a));
            }
            else if(str.find("front")==string::npos){
                for(int j=0;j<str.size();j++){
                    if(str[j]>='0' && str[j]<='9')
                        a.push_back(str[j]);
                }
                dq.push_back(stoi(a));
            }
            a.clear();
        }
    }
}