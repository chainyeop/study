#include<iostream>
using namespace std;
int main(){
    int a,b,num1,num2,r;
    cin>>a>>b;
    num1=a;
    num2=b;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    cout<<a<<endl;
    cout<<num1/a * num2/a * a;
}