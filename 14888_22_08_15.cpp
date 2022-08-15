// 예전에 썼던 백트래킹 코드를 참고로 하여 문제를 해결했다. 생각보다 어렵지 않았지만 실행 시간이 오래 걸렸다.
// 굉장히 비효율적인 코드라는 반증이라 좀 더 효율적으로 작성할 수 있는 방법을 찾아봐야겠다.

#include<iostream>
#include<vector>
using namespace std;

int number[11]={0};
int MAX=-1000000000,MIN=1000000000;
char sign[11]={0};
bool used[11]={false};
vector <char> sol;

void bt(int n){
    if(n-1==sol.size()){
        // for(int j=0;j<n-1;j++){
        //     cout<<sol[j]<<" ";
        // }
        int result=number[0];
        for(int j=1;j<n;j++){
            if(sol[j-1]=='+')
                result=result+number[j];
            else if(sol[j-1]=='-')
                result=result-number[j];
            else if(sol[j-1]=='*')
                result=result*number[j];
            else
                result=result/number[j];
        }
        if(MAX<result)
            MAX=result;
        if(MIN>result)
            MIN=result;
        //cout<<"\n";
        return;
    } 
    for(int i=1;i<=n-1;i++){
        if(used[i]==false){
            sol.push_back(sign[i]);
            used[i]=true;
            bt(n);
            sol.pop_back();
            used[i]=false;
        }
    }
}
int main(){
    int N,num,count=1;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        number[i]=num;
    }
    for(int i=0;i<4;i++){
        cin>>num;
        if(i==0){
            for(int j=0;j<num;j++){
                sign[count]='+';
                count++;
            }
        }
        else if(i==1){
            for(int j=0;j<num;j++){
                sign[count]='-';
                count++;
            }
        }
        else if(i==2){
            for(int j=0;j<num;j++){
                sign[count]='*';
                count++;
            }
        }
        else{
            for(int j=0;j<num;j++){
                sign[count]='/';
                count++;
            }
        }
    }
    bt(N);
    cout<<MAX<<"\n"<<MIN;
}