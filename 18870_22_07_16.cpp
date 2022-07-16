// #include<iostream> // 실행은 되지만 백준에 채점하면 시간초과 뜸. 어찌보면 당연
// #include<vector>
// #include<algorithm>
// #include<set>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N,num,i=0;
//     set <int> s;
//     set <int>::iterator iter1;
//     vector <int> v;
//     vector <int>::iterator iter2;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>num;
//         v.push_back(num);
//         s.insert(num);
//     }
//     for (iter1 = s.begin(); iter1 != s.end(); iter1++){
//         for (iter2 = v.begin(); iter2 != v.end(); iter2++){
//             if (*iter1 == *iter2){
//                 *iter2 = i;
//             }
//         }
//         i++;
//     }
//     for (iter2 = v.begin(); iter2 != v.end(); iter2++){
//         cout<<*iter2<<" ";
//     }
// }

// #include<iostream> // 이건 될줄 알았는데 이것도 시간초과 뜸
// #include<vector>
// #include<algorithm>
// #include<set>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N,num,i=0;
//     set <int> s;
//     set <int>::iterator iter1;
//     vector <int> v;
//     vector <int>::iterator iter2;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         cin>>num;
//         v.push_back(num);
//         s.insert(num);
//     }
//     for (iter2=v.begin();iter2!=v.end();iter2++){
//         cout<<*iter2<<" ";
//         auto it=s.find(*iter2);
//         cout<< it-s.begin()<< " ";
//     }
// }

#include<iostream> // 결국 이진 탐색 이용
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,num;
    vector <int> v;
    vector <int> sortv;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        v.push_back(num);
        sortv.push_back(num);
    }
    sort(sortv.begin(),sortv.end()); // vector의 값을 정렬
    sortv.erase(unique(sortv.begin(),sortv.end()),sortv.end()); // 정렬 된 값에서 중복을 제거함
    for(int i=0;i<N;i++){ // 이진 탐색으로 값을 찾음
        int end=sortv.size()-1,start=0,mid=0,check=0;
        while(start<=end){
            mid=(end+start)/2;
            if(v[i]==sortv[mid]){
                check=1;
                break;
            }
            else if(v[i]>sortv[mid])
                start=mid+1;
            else if(v[i]<sortv[mid])
                end=mid-1;
        }
        if(check==1)
            cout<<mid<<" ";
    }
}

