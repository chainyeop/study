// string을 다루는 부분이 생각보다 힘들었다.
// 처음에는 stoi함수에서 계속 오류가 발생하였다.
// 알고보니 cin으로 문자열을 입력받을 때는 공백은 들어가지 않는다는 사실을 간과했던 것이다.
// 그래서 stoi에 문자열을 넣었다고 생각했지만 들어가지 않았던 것이었다.
// 

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    int N;
    string str,a;
    stack <int> s;
    cin>>N;
    cin.ignore(256,'\n');   
    for(int i=0;i<N;i++){
        getline(cin,str);
        if(str=="pop"){
            if(s.empty())
                cout<<"-1"<<"\n";
            else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        }
        else if(str=="size"){
            cout<<s.size()<<"\n";
        }
        else if(str=="empty"){
            if(s.empty())
                cout<<"1"<<"\n";
            else
                cout<<"0"<<"\n";
        }
        else if(str=="top"){
            if(s.empty())
                cout<<"-1"<<"\n";
            else
                cout<<s.top()<<"\n";
        }
        else{
            for(int j=0;j<str.size();j++){
                if(str[j]>='0' && str[j]<='9'){
                    a.push_back(str[j]);
                }
            }
            s.push(stoi(a));
            a.clear();
        }
    }
}