#include<iostream>
#include<set>
using namespace std;
int main(){
    string str;
    char a[1000]={0};
    set <string> S;
    cin>>str;
    for(int i=0;i<str.size();i++){
        for(int j=0;j<str.size()-i;j++){
            for(int k=j;k<j+i+1;k++){
                a[k-j]=str[k];
            }
            S.insert(a);
        }
    }
    cout<<S.size();
}