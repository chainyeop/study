// 문제를 풀다가 감을 못잡아서 결국 구글링을 하여 힌트를 얻었다.
// 내가 생각했던만큼 크게 어려운 문제가 아니었다. 단지 bool형 변수를 하나 이용하여 부호의 +,- 유무를 판단할 뿐이었다.
// +부호는 상관없고 -부호가 나올 경우 그 뒤의 +를 전부 -로 바꿔 계산하는 것이었다.

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

// vector <int> v;
// vector <char> ch;

// int main(){
//     int arr[50]={0},k=0;
//     string str,a;
//     cin>>str;
//     for(int i=0;i<str.size();i++){
//         if(str[i]>='0'&& str[i]<='9'){
//             a.push_back(str[i]);
//         }
//         else{
//             v.push_back(stoi(a));
//             ch.push_back(str[i]);
//             a.clear();
//         }
//         if(i==str.size()-1){ // 문자열의 끝에 왔을 때
//             v.push_back(stoi(a));
//             a.clear();
//         }
//     }
//     for(int i=0;i<v.size();i++){
//         if(ch[i]=='-'){
//             sum=
//         }
//         else if(ch[i]=='+'){

//         }
//     }
// }

#include<iostream>
#include<string>
using namespace std;
int main(){
    int sum=0,num;
    string str,a;
    bool temp=false;
    cin>>str;
    for(int i=0;i<=str.size();i++){
        if(str[i]=='+'||str[i]=='-'||i==str.size()){
            if(temp==false){
                num=stoi(a);
                sum+=num;
                a.clear();
            }
            else{
                num=stoi(a);
                sum-=num;
                a.clear();
            }
            if(str[i]=='-')
                temp=true;
        }
        else{
            a.push_back(str[i]);
        }
    }
    cout<<sum;
}