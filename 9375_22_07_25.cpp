#include<iostream> // 처음에는 map이나 vector를 이용하려고 했었는데 multiset을 이용하니 훨씬 쉬웠다.
#include<set>
using namespace std;
int main(){
    int T,n,result;
    string a,b;
    multiset <string> ms;
    set <string> s;
    set <string>::iterator siter;
    cin>>T;
    for(int i=0;i<T;i++){
        result=1;
        cin>>n;
        if(n==0){
            cout<<0<<"\n";
            continue;
        }
        for (int j=0;j<n;j++){
            cin>>a>>b;
            s.insert(b);
            ms.insert(b);
        }
        for(siter=s.begin();siter!=s.end();siter++){
            result=result*(ms.count(*siter)+1);
        }
        cout<<result-1<<"\n";
        s.clear();
        ms.clear();
    }
}