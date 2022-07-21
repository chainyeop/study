#include<iostream> // dp의 메모이제이션 기법을 이용하여 문제를 해결함
using namespace std;

int arr[51][51][51]={0};

int w(int a,int b,int c){ // 이 함수는 보다 더 깔끔하게 구현 가능할거 같다.
    if(a<=-1 || b<=-1 || c<=-1)
        return 1;
    else if(arr[a][b][c]==0){
        if (a <= 0 || b <= 0 || c <= 0)
            arr[a][b][c] = 1;
        else if (a > 20 || b > 20 || c > 20)
            arr[a][b][c] = w(20, 20, 20);
        else if(a<b && b<c)
            arr[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        else
            arr[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return arr[a][b][c];
}

int main(){
    int a,b,c,result;
    for(;;){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)
            break;
        result=w(a,b,c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") "<<"= "<<result<<"\n";
    }
}