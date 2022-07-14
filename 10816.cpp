// #include<iostream>
// #include<set>
// using namespace std;
// int main(){
//     int N,M,cnt=0,a;
//     int Marr[500001]={0};
//     multiset <int> S;
//     multiset <int>::iterator iter;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>a;
//         S.insert(a);
//     }    
//     cin>>M;
//     for(int i=0;i<M;i++){
//         cnt=0;
//         cin>>Marr[i];
//         pair<multiset<int>::iterator,multiset<int>::iterator> num=S.equal_range(Marr[i]);
//         for(iter=num.first;iter!=num.second;iter++){
//             cnt++;
//         }
//         cout<<cnt<<" ";
//     }
// }   

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,M,num1,num2;
    int Narr[5001]={0};
    int Marr[5001]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Narr[i];
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>Marr[i];
    }
    sort(Narr,Narr+N);
    
    for(int i=0;i<M;i++){
        num1=lower_bound(Narr,Narr+N,Marr[i])-Narr;
        num2=upper_bound(Narr,Narr+N,Marr[i])-Narr;
        cout<< num2 - num1<<" ";
    }
    
}
