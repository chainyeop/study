// #include<iostream> // 처음엔 이 코드로 했다가 50점이 나와서 시간이 오래걸려서 그런거라고 생각했다.
// #include<string> 
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     string str;
//     int q,l,r,cnt[26][2000]={0},ans=0;
//     char c;
//     cin>>str;
//     cin>>q;
//     for(int i=0;i<str.length();i++){
//         cnt[str[i]-'a'][i]++;
//     }
//     for(int i=0;i<26;i++){ // 알파벳 개수만큼 반복
//         for(int j=1;j<=str.length();j++){ // 문자열의 길이만큼 반복
//             cnt[i][j]=cnt[i][j]+cnt[i][j-1];
//         }
//     }
//     // for(int i=0;i<26;i++){ // 알파벳 개수만큼 반복
//     //     for(int j=0;j<str.length();j++){ // 문자열의 길이만큼 반복
//     //         cout<<cnt[i][j]<<" ";
//     //     }
//     //     cout<<"\n";
//     // }
//     for(int i=0;i<q;i++){
//         cin>>c>>l>>r;
//         if(l==0)
//             ans=cnt[c-'a'][r];
//         else
//             ans=cnt[c-'a'][r]-cnt[c-'a'][l-1];
//         cout<<ans<<"\n";    
//     }
// }

// 그래서 다음과 같이 문자의 갯수를 세면서 바로바로 더해주었다.
// 그러나 이 방법도 50점이 떴고 알고보니 배열의 크기 설정에서 실수가 있었다.
// cnt[26][200000]으로 제출했는데 20만을 200001로 바꾸니 통과되었다.
// 이 코드가 위의 코드보다 조금 더 빨랐지만 그렇게 큰 차이는 아니었다.
#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int q,l,r,cnt[26][2000]={0},ans=0;
    char c;
    cin>>str;
    cin>>q;
    cnt[str[0]-'a'][0]++;
    for(int i=0;i<26;i++){ // 알파벳 개수만큼 반복
        for(int j=1;j<=str.length();j++){ // 문자열의 길이만큼 반복
            if(str[j]-'a'==i){
                cnt[str[j]-'a'][j]++;
            }
            cnt[i][j]=cnt[i][j]+cnt[i][j-1];
        }
    }
    // for(int i=0;i<26;i++){ // 알파벳 개수만큼 반복
    //     for(int j=0;j<str.length();j++){ // 문자열의 길이만큼 반복
    //         cout<<cnt[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<q;i++){
        cin>>c>>l>>r;
        if(l==0)
            ans=cnt[c-'a'][r];
        else
            ans=cnt[c-'a'][r]-cnt[c-'a'][l-1];
        cout<<ans<<"\n";    
    }
}