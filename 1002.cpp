#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T,x1,x2,y1,y2,r1,r2;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2; // 원의 중심이 같은 경우
        if(x1==x2 && y1==y2){
            if(r1==r2)
                cout<<-1<<"\n";
            else
                cout<<0<<"\n";
        }
        else if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))+r1<r2 || sqrt(pow(x1-x2,2)+pow(y1-y2,2))+r2<r1) // 한 원이 다른 원의 내부에 들어가 있는 경우
            cout<<0<<"\n";
        else if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))+r1==r2 ||sqrt(pow(x1-x2,2)+pow(y1-y2,2))+r2==r1) // 원이 내부의 한 점에서 만나는 경우
            cout<<1<<"\n";
        else if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))==r1+r2) // 원이 바깥의 한 점에서 만나는 경우
            cout<<1<<"\n";
        else if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))<r1+r2){ // 두 점에서 만나는 경우
            cout<<2<<"\n";
        }
        else if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))>r1+r2) // 원이 서로 안겹치는 경우
            cout<<0<<"\n";
    }
}