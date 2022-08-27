// 입력 값이 2^31이어서 분명 공식을 사용하는 문제일거라 생각했다.
// 그래서 나오는 값들의 패턴을 찾으려고 해봤지만 쉽게 찾을수 없었다.
// 그래서 검색을 통해 어떤 패턴이 있는지를 보았다. 처음에는 이게 무슨 패턴인지도 이해가 잘 안가서 한참 들여다 봤다.
// 패턴을 이해하고 난 후에 코드를 작성하는 것은 그렇게 어렵지 않았다.

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T;
    long long x,y;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>x>>y;
        long long num=y-x;
        long long s=(int)sqrt(num);
        if(s*s==num)
            cout<<2*s-1<<"\n";
        else if(s*s<num && num<=(s*s+(s+1)*(s+1))/2)
            cout<<2*s<<"\n";
        else if((s*s+(s+1)*(s+1))/2<num && num<(s+1)*(s+1))
            cout<<2*s+1<<"\n";
    }
}