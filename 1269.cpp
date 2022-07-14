#include<iostream>
#include<set>
using namespace std;
int main(){
    int a,b,num,cnt=0;
    set<int> A;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>num;
        A.insert(num);
    }
    for(int i=0;i<b;i++){
        cin>>num;
        if(A.find(num)!=A.end())
            cnt++;
    }
    cout<<a-cnt+b-cnt;
}