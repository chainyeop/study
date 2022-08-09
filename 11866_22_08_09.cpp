#include<iostream>
#include<queue>
using namespace std;
int main(){
    int N,K;
    queue <int> q;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    cout<<"<";
    while(1){
        if(q.empty())
            break;
        for(int i=0;i<K-1;i++){
            q.push(q.front()); 
            q.pop();
        }
        if(q.size()!=1)
            cout<<q.front()<<", ";
        else
            cout<<q.front()<<">";
        q.pop();
    }
}