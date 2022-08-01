// 저번학기에 썼던 알고리즘 교재에 나온 파이썬 코드를 참고하였다.
// 8이상의 수를 입력하면 값이 제대로 나오지 않아 막혔었다.
// issafe함수에 for문 조건을 ||에서 &&으로 바꿔주니 정상 작동하였다.
// 다만 실행 시간이 굉장히 오래 나와서 나중에 다른 방식으로 풀어봐야겠다.
#include<iostream>
using namespace std;

int board[15][15]={0};
int n,cnt=0;

bool issafe(int x,int y){
    for(int i=0;i<y;i++){
        if(board[i][x]==1) return false;
    }
    for(int i=y-1,j=x-1;i>-1&&j>-1;i--,j--){
        if(board[i][j]==1) return false;            
    }
    for(int i=y-1,j=x+1;i>-1&&j<n;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

// void pboard(int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(board[i][j]==1)
//                 cout<<"Q"<<" ";
//             else
//                 cout<<"."<<" ";
//         }
//         cout<<"\n";
//     }
//     cout<<"\n";
// }

int nqueen(int y){
    if(y==n){
        cnt++;
        //pboard(n);
        return 0;
    }
    for(int x=0;x<n;x++){
        if(issafe(x,y)==true){
            board[y][x]=1;
            nqueen(y+1);
            board[y][x]=0;
        }
    }
    return cnt;
}

int main(){
    cin>>n;
    cout<<nqueen(0);
}