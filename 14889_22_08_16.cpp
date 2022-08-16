// 문제를 착각해서 그렇게 어렵지 않은 문제였지만 시간을 많이 잡아먹었다.
// 처음에는 N명 중에서 N/2명을 뽑아서 각각을 계산해준 다음 각각의 값끼리 하나하나 다 빼줘야 한다고 생각했다.
// 그러나 사실은 0, 1, 2 이렇게 3명을 뽑았다면 나머지 3, 4, 5끼리의 각각의 합을 빼주기만 하면 되었다.
// 이 부분을 나중에 깨달았고 그로 인해 코드를 다시 고치느라 시간이 정말 많이 걸렸다.

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits>
using namespace std;

int arr[20][20]={0},answer=INT_MAX;
bool used[20]={false};
vector <int> sol;
vector <int> sol2;

void bt(int n,int num){ // N명의 사람중 N/2의 사람을 먼저 뽑는다.
    int result=0,result1=0,sum,sum1;

    if(sol.size()==n/2){
        for(int a=0;a<n;a++){
            if(find(sol.begin(),sol.end(),a)==sol.end())
                sol2.push_back(a);
        }
        for(int a=0;a<n/2-1;a++){
            for(int b=a+1;b<n/2;b++){
                sum=arr[sol[a]][sol[b]]+arr[sol[b]][sol[a]];
                sum1=arr[sol2[a]][sol2[b]]+arr[sol2[b]][sol2[a]];
                result=result+sum;
                result1=result1+sum1;
            }
        }
        int ans=abs(result-result1);
        if(answer>ans) answer=ans;
        sol2.clear();
        return;
    }
    for(int i=num;i<n;i++){
        if(used[i]==false){
            sol.push_back(i);
            used[i]=true;
            bt(n,i+1);
            sol.pop_back();
            used[i]=false;
        }
    }
}
int main(){
    int N,number;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>number;
            arr[i][j]=number;
        }
    }
    bt(N,0);
    cout<<answer;
}