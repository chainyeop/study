#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string str;
    set <string> s[51];
    set <string>::iterator iter;
    for(int i=0;i<N;i++){
        cin>>str;
        s[str.size()].insert(str);
    }
    for (int i=1;i<=50;i++){
        for (iter = s[i].begin(); iter != s[i].end(); iter++){
            cout << *iter << endl;
        }
    }
}