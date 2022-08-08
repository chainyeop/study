#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    stack <char> st;
    string str;
    for(;;){
        int check=0;  
        getline(cin,str);
        if(str==".")
            return 0;
        for(int i=0;i<str.size();i++){
            if(str[i]==')'){
                if(st.empty()){
                    cout<<"no"<<"\n";
                    check=1;
                    break;
                }
                if(st.top()=='(')
                    st.pop();
                else
                    st.push(str[i]);
            }
            else if(str[i]==']'){
                if(st.empty()){
                    cout<<"no"<<"\n";
                    check=1;
                    break;
                }
                if(st.top()=='[')
                    st.pop();
                else
                    st.push(str[i]);
            }
            else if(str[i]=='(' || str[i]=='[')
                st.push(str[i]);
            else
                continue;
        }
        if(check!=1){
            if(st.empty())
                cout<<"yes"<<"\n";
            else
                cout<<"no"<<"\n";
        }
        str.clear();
        while(!st.empty()){
            st.pop();
        }
    }
}