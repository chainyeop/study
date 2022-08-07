// 쉬운 문제였지만 생각보다 헤맸던 문제였다.
// 문자열을 입력받고 그 문자열에 대해 판단한 후 마지막에 스택을 비워줘야했다.
// 이 부분에서 스택이 제대로 비워지지 않아 계속 오류가 떴고 마지막에는 while문을 이용해서 겨우 제대로 비울수 있었다.

// #include<iostream>
// #include<string>
// #include<stack>
// using namespace std;

// int main(){
//     int N,check;
//     string str;
//     stack <char> s;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>str;
//         check=0;
//         for(int j=0;j<str.size();j++){
//             if(s.empty() && str[j]==')'){
//                 cout<<"NO"<<"\n";
//                 check=1;
//                 break;
//             }
//             if(str[j]=='('){
//                 s.push(str[j]);
//             }
//             if(str[j]==')' && s.top()=='('){
//                 s.pop();
//             }
//         } 
//         if(check!=1){
//             if(s.empty())
//                 cout<<"YES"<<"\n";
//             else
//                 cout<<"NO"<<"\n";
//         }
//         str.clear();
//         while(!s.empty()){
//             s.pop();
//         }
//     }
// }

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    int N,check;
    string str;
    stack <char> s;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        check=0;
        for(int j=0;j<str.size();j++){
            if(str[j]==')'){
                if(s.empty()){
                    cout<<"NO"<<"\n";
                    check=1;
                    break;
                }
                if(s.top()=='(')
                    s.pop();
            }
            else if(str[j]=='(')
                s.push(str[j]);
        } 
        if(check!=1){
            if(s.empty())
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
        str.clear();
        while(!s.empty()){
            s.pop();
        }
    }
}