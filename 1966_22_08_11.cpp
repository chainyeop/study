#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int T,N,M,num,p,v;
    queue <pair<int,int>> q;
    priority_queue<int> pq;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N>>M;
        for(int j=0;j<N;j++){
            cin>>num;
            pq.push(num);
            q.push(make_pair(j,num));
        }
        int cnt=0;
        for(;;){
            int index=q.front().first;
            int value=q.front().second;
            q.pop();
            if(pq.top()==value){
                pq.pop();
                cnt++;
                if(M==index){
                    cout<<cnt<<"\n";
                    break;    
                }
            }
            else
                q.push(make_pair(index,value));
        }
        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();      
    }
}