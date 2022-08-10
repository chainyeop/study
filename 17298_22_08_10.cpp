// 처음에는 이중반복문을 이용하여 풀어보려고 했으나 당연히 시간초과가 떴다.
// 다른 방법을 찾다가 구글링을 통해 힌트를 얻어 해결하였다.

// #include<iostream>
// #include<queue>
// using namespace std;
// int main(){
//     int N,num,arr[10000]={0};
//     queue <int> q;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     for(int i=0;i<N;i++){
//         for(int j=i+1;j<N;j++){
//             if(arr[i]<arr[j])
//                 q.push(arr[j]);
//         }
//         if(q.empty())
//             cout<<"-1";
//         else
//             cout<<q.front();
//         cout<<" ";
//         while(!q.empty()){
//             q.pop();
//         }
//     }
// }

// #include<iostream>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N,num,arr[10000]={0};
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>num;
//         arr[i]=num;
//     }
//     for(int i=0;i<N;i++){
//         int check=0;
//         for(int j=i+1;j<N;j++){
//             if(arr[i]<arr[j]){
//                 cout<<arr[j];
//                 check=1;
//                 break;
//             }        
//         }
//         if(check==0)
//             cout<<"-1";
//         cout<<" ";
//     }
// }

// 처음 봤을 때는 힌트가 무슨 말인지 몰라 이해하는데 시간이 걸렸지만 결국에는 이를 토대로 문제를 해결했다.
#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,num,arr[10000]={0};
    stack <int> st;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr[i]=num;
    }
    for(int i=0;i<N;i++){
        if(st.empty())
            st.push(i);
        else{
            if(arr[st.top()]>arr[i])
                st.push(i);
            else if(arr[st.top()]<arr[i]){
                while(!st.empty()){
                    if(arr[st.top()]<arr[i]){
                        arr[st.top()]=arr[i];
                        st.pop();
                    }
                    else if(arr[st.top()>arr[i]]){
                        st.push(i);
                        break;
                    }
                }
            }
        }
        if(st.empty())
            st.push(i);
    }
    while(!st.empty()){
        arr[st.top()]=-1;
        st.pop();
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
}