// #include<iostream> // 시도하다 실패한 코드
// using namespace std;
// int main(){
//     int N,cnt;
//     cin>>N;
//     for (int i = 0; i < N; i++){
//         cnt=0;
//         for (int j = 0; j < N; j++){
//             if (i % 3 == 1 && j % 3 == 1)
//                 cout << " ";
//             // else if(i>=3+i*9 &&i<=5+i*9 && j>=3+cnt*9&&j<=5+cnt*9)
//             //     cout<<" ";
//             else if((i%9==3||i%9==4||i%9==5) && (j%9==3||j%9==4||j%9==5))
//                 cout<<" ";
//             else if(i)
//                 cout<<" ";    
//             else if(i>=N/3&&i<2*N/3 && j>=N/3&&j<2*N/3)
//                 cout<<" "; 
//             else
//                 cout << "*";
//             cnt++; 
//         }
//         cout << endl;
//     }
// }

// 시간을 많이 투자했지만 결국 스스로 해결하는데는 실패함
// 구글에 검색해서 다른 사람의 코드를 참고하여 해결했음
#include<iostream> 
using namespace std;

stars(int i,int j,int N){
    if(N==0)
        cout<<"*";
    else if((i/N)%3==1 && (j/N)%3==1) // 이 규칙을 찾는데 결국 찾지 못했고 스스로 못찾은게 아쉬웠음
        cout<<" ";
    else
        stars(i,j,N/3);
    return 0;
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            stars(i,j,N);
        }
        cout<<"\n";
    }
}