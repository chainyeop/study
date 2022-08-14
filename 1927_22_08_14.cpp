// 구글링을 해보니 우선순위 큐를 다음과 같이 선언하면 작은수부터 정렬이 가능하다고 했다.
// priority_queue <int,vector<int>,greater<int>> pq; greater<int>의 같은 경우 예전에도 몇번 본적이 있었다.
// 중간에 vector<int> 이 부분을 넣는 것은 처음 보았는데 이 부분이 없으니 실행이 되지 않았다.

#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue <int,vector<int>,greater<int>> pq;
    int N,x;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<"0"<<"\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else pq.push(x);
    }
}