// 다 풀어놓고는 마지막에 숫자 하나를 잘못적어서 시간을 허비했다.
// answer[n]에 처음에 0을 넣어야 하는데 1을 넣어서 나온 결과를 보고 코드가 틀렸다고 착각했다.
// 밑에는 visited배열 없이 만든 코드인데 당연히 될리가 없었다.

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int visited[100001]={0};
int m[2]={-1,1};
int answer[100001]={0};
queue <int> q;

void bfs(int n,int k){
    visited[n]=1;
    q.push(n);
    answer[n]=0;
    while(!q.empty()){
        int qn=q.front();
        q.pop();
        for(int i=0;i<2;i++){
            if(m[i]+qn>=0 && m[i]+qn<=100000){
                if(visited[m[i]+qn]==0){
                    visited[m[i]+qn]=1;
                    answer[m[i]+qn]=answer[qn]+1;
                    q.push(m[i]+qn);
                }
            }
        }
        if(2*qn>=0 && 2*qn<=100000){
            if(visited[2*qn]==0){
                visited[2*qn]=1;
                answer[2*qn]=answer[qn]+1;
                q.push(2*qn);
            }
        }
    }
}
int main(){
    int N,K;
    cin>>N>>K;
    bfs(N,K);
    // for(int i=N;i<=K+1;i++){
    //     cout<<answer[i]<<" ";
    // }
    // cout<<"\n";
    cout<<answer[K];
}

// #include<iostream>
// #include<queue>
// #include<algorithm>
// using namespace std;

// int h_s[100001]={0};
// int m[2]={-1,1};
// int answer[100010]={0};
// queue <int> q;

// void bfs(int n,int k){
//     q.push(n);
//     answer[n]=0;
//     while(!q.empty()){
//         int qn=q.front();
//         q.pop();
//         for(int i=0;i<2;i++){
//             if(m[i]+qn>=0 && m[i]+qn<=100000){
//                 if(answer[m[i]+qn]!=0){ // 값이 있을 경우
//                     answer[m[i]+qn]=min(answer[qn]+1,answer[m[i]+qn]); // 더 작은 값을 넣어줌
//                     q.push(m[i]+qn);
//                 }
//                 else{ // 값이 없을 경우
//                     answer[m[i]+qn]=answer[qn]+1;
//                     q.push(m[i]+qn);
//                 }
//             }
//             if(m[i]+qn==k) return; // k의 위치에 도달하면 종료
//         }
//         if(2*qn>=0 && 2*qn<=100000){
//             if(answer[2*qn]!=0){ // 값이 있을 경우
//                 answer[2*qn]=min(answer[qn]+1,answer[2*qn]);
//                 q.push(2*qn);
//             }
//             else{ // 값이 없을 경우
//                 answer[2*qn]=answer[qn]+1;
//                 q.push(2*qn);
//             }
//         }
//         if(2*qn==k) return; // k의 위치에 도달하면 종료
//     }
// }
// int main(){
//     int N,K;
//     cin>>N>>K;
//     if(N==K){
//         cout<<"0";
//         return 0;
//     }
//     bfs(N,K);
//     // for(int i=1;i<=K+1;i++){
//     //     cout<<answer[i]<<" ";
//     // }
//     // cout<<"\n";
//     cout<<answer[K];
// }