// 첫번째 주석 처리된 코드는 vscode에서는 잘 실행이 되었는데 백준에 제출만 하면 런타임에러(seg fault)가 떠서 해결하는데 애를 먹었다.
// string을 char로도 써보고 하다가 결국 런타임에러가 뜨는 원인은 찾지 못했다.
// 원래 아래의 코드를 넣으면 시간초과가 뜰것이라고 생각하고 제출을 해본것이었는데 계속 런타임에러가 나와 정말 당황스러웠다.
// 주석 처리된 코드는 R을 만날때마다 deque에 있는 수들을 뒤집어 줬다. 
// 두번째 코드에는 R의 개수에 따라 앞, 뒤에서 pop을 하는지를 결정해 주었다. 이와 같이 코드를 바꾸니 바로 통과되었다.
// 내 생각이지만 seg fault의 원인이 riter를 사용한 부분에 있지 않았을까 하는 생각이 든다.

// #include<iostream>
// #include<deque>
// #include<string>
// using namespace std;
// int main(){
//     int T,n;
//     string p,num,a;
//     deque <int> dq;
//     deque <int>::reverse_iterator riter;
//     cin>>T;
//     for(int i=0;i<T;i++){
//         int check=0;
//         cin>>p;
//         cin>>n;
//         cin>>num;
//         for(int j=1;j<num.size()-1;j++){ // deque에 숫자를 넣는 반복문
//             if(num[j]>='0' && num[j]<='9'){ // 숫자를 만났을 때
//                 if(num[j+1]>='0' && num[j+1]<='9') // 다음 문자도 숫자일 경우
//                     a.push_back(num[j]);
//                 else{ // 숫자가 아닐 때
//                     a.push_back(num[j]);
//                     dq.push_back(stoi(a));
//                     a.clear();
//                 }
//             }
//         }
//         for(int j=0;j<p.size();j++){
//             if(p[j]=='R'){
//                 for(riter=dq.rbegin();riter!=dq.rend();riter++) // 이 부분에 문제가 있지 않았을까 싶다.
//                     dq.push_back(*riter);
//                 // for(int k=0;k<dq.size();k++){
//                 //     cout<<dq[k]<<" ";
//                 // }
//                 //cout<<"\n";
//                 int ds=dq.size()/2;
//                 for(int k=0;k<ds;k++){
//                     //cout<<k<<" ";
//                     dq.pop_front();
//                 }
//             }
//             else if(p[j]=='D'){
//                 if(dq.empty()) {
//                     check=1;
//                     cout<<"error"<<"\n";
//                     break;
//                 }
//                 else dq.pop_front();
//             }
//         }
//         if(check==1) { // error를 출력 했을 경우 바로 다음 테스트 케이스로 넘어감
//             a.clear();
//             dq.clear();
//             continue;
//         }
//         cout<<"[";
//         for(int i=0;i<dq.size();i++){
//             if(i==dq.size()-1)
//                 cout<<dq[i];
//             else
//                 cout<<dq[i]<<",";
//         }
//         cout<<"]"<<"\n";
//         a.clear();
//         dq.clear();
//     }
// }

#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T,n;
    string p,num,a;
    deque <int> dq;
    deque <int>::reverse_iterator riter;
    cin>>T;
    for(int i=0;i<T;i++){
        int check=0,cnt=1;
        cin>>p;
        cin>>n;
        cin>>num;
        for(int j=1;j<num.size()-1;j++){ // deque에 숫자를 넣는 반복문
            if(num[j]>='0' && num[j]<='9'){ // 숫자를 만났을 때
                if(num[j+1]>='0' && num[j+1]<='9') // 다음 문자도 숫자일 경우
                    a.push_back(num[j]);
                else{ // 숫자가 아닐 때
                    a.push_back(num[j]);
                    dq.push_back(stoi(a));
                    a.clear();
                }
            }
        }
        for(int j=0;j<p.size();j++){
            if(p[j]=='R')
                cnt++;
            else if(p[j]=='D'){
                if(dq.empty()) {
                    check=1;
                    cout<<"error"<<"\n";
                    break;
                }
                if(cnt%2==1) // 정방향
                    dq.pop_front();
                else if(cnt%2==0) // 역방향
                    dq.pop_back();
            }
        }
        if(check==1) { // error를 출력 했을 경우 바로 다음 테스트 케이스로 넘어감
            a.clear();
            dq.clear();
            continue;
        }
        cout<<"[";
        if(cnt%2==1){ // 정방향
            for(int i=0;i<dq.size();i++){
                if(i==dq.size()-1) cout<<dq[i];
                else cout<<dq[i]<<",";
            }
        }
        else if(cnt%2==0){ // 역방향
            for(int i=dq.size()-1;i>=0;i--){
                if(i==0) cout<<dq[i];
                else cout<<dq[i]<<",";
            }
        }
        cout<<"]"<<"\n";
        // if(!dq.empty()){
        //     cout<<"[";
        //     for(int i=0;i<dq.size()-1;i++)
        //         cout<<dq[i]<<",";
        //     cout<<dq[dq.size()-1]<<"]"<<"\n";    
        // }
        //else cout<<"[]"<<"\n";
        a.clear();
        dq.clear();
    }
}