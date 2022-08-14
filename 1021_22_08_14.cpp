#include<iostream>
#include<deque>
using namespace std;

int main(){
    int N,M,num,arr[50]={0},cnt=0,n=0;
    deque <int> dq;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num;
        arr[i]=num;
    }
    for(int i=1;i<=N;i++){
        dq.push_back(i);
    }
    for(int i=0;i<M;i++){
        if(arr[i]==dq.front()) // 뺄 숫자를 만났을 경우
            dq.pop_front();
        else{ // 못 만났을 경우
            for(int j=1;j<dq.size();j++){ // 뺄 숫자의 위치를 찾아줌
                if(arr[i]==dq[j]){
                    n=j+1; // n에 저장
                    break;
                }
            }
            if(dq.size()%2==1){ // 덱의 크기가 홀수일 경우
                if(n<=dq.size()/2+1){ // pop할 수가 좌측에 있는 경우
                    for(int j=0;j<n-1;j++){
                        dq.push_back(dq.front());
                        dq.pop_front();
                        cnt++;
                    }
                    cout<<cnt<<"\n";
                    dq.pop_front();
                }
                else{ // 우측에 있는 경우
                    for(int j=0;j<dq.size()-n+1;j++){
                        dq.push_front(dq.back());
                        dq.pop_back();
                        cnt++;
                    }
                    cout<<cnt<<"\n";
                    dq.pop_front();
                }
            }
            else if(dq.size()%2==0){ // 덱의 크기가 짝수일 경우
                if(n<=dq.size()/2){
                    for(int j=0;j<n-1;j++){
                        dq.push_back(dq.front());
                        dq.pop_front();
                        cnt++;
                    }
                    cout<<cnt<<"\n";
                    dq.pop_front();
                }
                else{
                    for(int j=0;j<dq.size()-n+1;j++){
                        dq.push_front(dq.back());
                        dq.pop_back();
                        cnt++;
                    }
                    cout<<cnt<<"\n";
                    dq.pop_front();
                }
            }
        }
    }
    cout<<cnt;
}