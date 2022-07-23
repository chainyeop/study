// 스스로 풀려고 시도해봤는데 쉽지 않아서 학기중에 썼던 교재에 나온 파이썬 코드를 참고했다.
// 참고해서 풀면 쉽게 해결할줄 알았는데 코드 이해하는데 오히려 시간이 더 걸렸다.
/* 횟수를 출력할 때 pow 함수를 이용하여 출력을 했었는데 그렇게 하니 입력이 커졌을 때
 정수로 출력되지 않는 문제가 있었다. 그래서 반복문을 이용하여 정수를 출력해주었다.*/
#include<iostream>
using namespace std;

void hanoi(int n,int a,int b,int c){
    if(n==1){
        cout<<a<<" "<<c<<"\n";
        return;
    }
    else{
        hanoi(n-1,a,c,b);
        cout<<a<<" "<<c<<"\n";
        hanoi(n-1,b,a,c);
    }
}
int main(){
    int N,num=1;
    cin>>N;
    for(int i=0;i<N;i++){
        num*=2;
    }
    cout<<num-1<<"\n";
    hanoi(N,1,2,3);
}