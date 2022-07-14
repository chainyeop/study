#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string b;
    cin>>b;
    sort(b.begin(),b.end(),greater<int>());
    cout<<b;
}