#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    int n,num,arr[1000]={0},cnt=0;
    cin>>n;
    stack <int> st;
    vector <char> v;
    for(int i=1;i<=n;i++){
        cin>>num;
        arr[i]=num;
    }
    int cur=arr[1];
    for(int i=1;i<=n;i++){
        st.push(i);
        v.push_back('+');
        while(1){
            if(cur==st.top()){
                st.pop();
                v.push_back('-');
                cnt++;
                cur=arr[1+cnt];
            }
            else
                break;
            if(st.empty()){
                break;
            }
        }
    }
    if(st.empty()){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<"\n";
        }
    }
    else
        cout<<"NO";
}