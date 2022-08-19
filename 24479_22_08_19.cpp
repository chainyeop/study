// 힌트를 통해 아래의 코드를 작성할 수 있었다.
// 처음에는 vector에 pair를 이용해서 두개의 변수를 저장할수 있도록 코드를 작성했다.
// 그런데 아래의 코드는 예제는 통과하는데 제출만 하면 런타임에러(out of bound)가 떴다.
// 그래서 구글링을 통해 그 밑에 있는 코드 처럼 pair를 사용하지 않고 입력 받을 때 두 수를 바꿔서 한번더 vector에 넣어 주었다.

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// vector <pair<int,int>> graph[100001];

// int visited[100001]={0},cnt=1;
// int num[100001]={0};

// void dfs(int n,int m,int r){
//     //if(visited[r]==1) return;
//     visited[r]=1;
//     num[r]=cnt;
//     cnt++;

//     for(int i=0;i<graph[r].size();i++){
//         if(visited[graph[r][i].second]==0)
//             dfs(n,m,graph[r][i].second);
//     }
// }

// int main(){
//     int N,M,R,u,v;
//     cin>>N>>M>>R;
//     for(int i=1;i<=M;i++){
//         cin>>u>>v;
//         graph[u].push_back(pair<int,int> (u,v));
//     }
//     for(int i=1;i<=N;i++){
//         sort(graph[i].begin(),graph[i].end());
//     }
//     for(int i=1;i<=M;i++){
//         for(int j=0;j<graph[i].size();j++){
//             cout<<graph[i][j].first<<" "<<graph[i][j].second<<"\n";
//         }
//     }
//     dfs(N,M,R);
//     for(int i=1;i<=N;i++){
//         cout<<num[i]<<"\n";
//     }
// }

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector <int> graph[100001];

int visited[100001]={0},cnt=1;
int num[100001]={0};

void dfs(int n,int m,int r){
    visited[r]=1;
    num[r]=cnt;
    cnt++;

    for(int i=0;i<graph[r].size();i++){
        if(visited[graph[r][i]]==0)
            dfs(n,m,graph[r][i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,R,u,v;
    cin>>N>>M>>R;
    for(int i=1;i<=M;i++){
        cin>>u>>v;
        graph[u].push_back(v); // 이 부분이 이해가 잘 가지 않았는데 내가 무방향 그래프라는 것을 간과하고 있었다.
        graph[v].push_back(u); // 1에서 2로가는 간선이 있다면 그 간선은 2에서 1로 가는 간선과 똑같이 때문에 
    }                          // u, v의 위치를 바꾼 값도 넣어줘야 하는 것이다.
    for(int i=1;i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    for(int i=1;i<=M;i++){
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<"\n";
        }
    }
    dfs(N,M,R);
    for(int i=1;i<=N;i++){
        cout<<num[i]<<"\n";
    }
}