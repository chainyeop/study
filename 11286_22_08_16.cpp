// 어떻게 풀지 몰라 고민하다가 우선순위 큐를 2개 사용한다는 말을 보고 바로 해결했다.
// 힌트를 토대로 하니 금방 풀 수 있었다.

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,x;
    priority_queue <int,vector<int>,greater<int>> plusq;
    priority_queue <int> minusq;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x==0){
            if(plusq.empty()&&minusq.empty()) cout<<"0"<<"\n";
            else if(plusq.empty() || minusq.empty()){
                if(plusq.empty()){
                    cout<<minusq.top()<<"\n";
                    minusq.pop();
                }
                else if(minusq.empty()){
                    cout<<plusq.top()<<"\n";
                    plusq.pop();
                }
            }
            else{
                if(plusq.top()==abs(minusq.top())){
                    cout<<minusq.top()<<"\n";
                    minusq.pop();
                }
                else if(plusq.top()>abs(minusq.top())){
                    cout<<minusq.top()<<"\n";
                    minusq.pop();
                }
                else{
                    cout<<plusq.top()<<"\n";
                    plusq.pop();
                }
            }
        }
        else{
            if(x>0) plusq.push(x);
            else if(x<0) minusq.push(x);
        }
    }
}