// 처음 시작할 때 우선순위 큐를 두 개 사용한다는 것을 알고 풀었는데도 불구하고 계속 시간초과가 떴다.
// 우선순위 큐를 하나만 써서 시간초과가 나온다면 그건 당연한 건데 두 개를 써서 풀었는데도 시간초과가 나서 당황스러웠다.
// 처음에 풀었던 방식은 maxpq에 있는 최댓값보다 num이 작다면 maxpq에 삽입하고 
// minpq에 있는 최솟값보다 num이 크다면 minpq에 삽입하는 식으로 해결하려고 했다.
// 이 방법은 작년 자료구조 시간에 썼던 자료에 나온 내용을 참고하였다.
// 구글링을 통해 찾은 방법은 각 큐의 크기가 같다면 maxpq에 삽입하고 그렇지 않다면 minpq에 삽입하는 방식이었다.
// maxpq보다 minpq가 클 경우에만 각 top값을 바꿔주기만 하면 되었다.
// 나중에 처음에 푼 코드에 cin, cout 최적화 문장을 넣어주니 시간초과가 안뜨긴했다.
// 그러나 계속 틀렸다고 나왔고 아직 처음에 푼 방식으로는 해결하지 못했다.

// #include<iostream>
// #include<queue>
// #include<cstdlib>
// using namespace std;
// int main(){
//     int N,num;
//     priority_queue <int,vector<int>,greater<int>> minpq;
//     priority_queue <int> maxpq;
//     cin>>N;
//     for(int i=1;i<=N;i++){
//         cin>>num;
//         maxpq.push(num);
//         int r=maxpq.size()-minpq.size();
//         if(abs(r)==2){ // 수의 개수가 2개 차이가 날 경우 개수가 적은 곳으로 수를 한 개 옮겨줌
//             if(maxpq.size()>minpq.size()){
//                 minpq.push(maxpq.top());
//                 maxpq.pop();
//             }
//             else if(maxpq.size()<minpq.size()){
//                 maxpq.push(minpq.top());
//                 minpq.pop();
//             }
//         }
//         if(maxpq.size()>minpq.size())
//             cout<<maxpq.top()<<"\n";
//         else if(maxpq.size()<minpq.size())
//             cout<<minpq.top()<<"\n";
//         else if(maxpq.size()==minpq.size()){
//             if(maxpq.top()>minpq.top()) cout<<minpq.top()<<"\n";
//             else if(maxpq.top()<minpq.top()) cout<<maxpq.top()<<"\n";
//         }
//     }
// }

#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int main(){
    int N,num;
    priority_queue <int,vector<int>,greater<int>> minpq;
    priority_queue <int> maxpq;
    cin>>N;
    cin>>num;
    maxpq.push(num);
    cout<<maxpq.top()<<"\n";
    for(int i=1;i<N;i++){
        cin>>num;     
        
        if(maxpq.size()==minpq.size()) maxpq.push(num);
        else minpq.push(num);

        if(maxpq.top()>minpq.top()){
            int a=maxpq.top();
            int b=minpq.top();
            maxpq.pop(); minpq.pop();
            maxpq.push(b); minpq.push(a);
        }
        cout<<maxpq.top()<<"\n";
    }
}