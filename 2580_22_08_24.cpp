// 처음 입력을 받을 때 0인 칸의 인덱스를 따로 vector에 넣는것 까지는 좋았다.
// 그 뒤에 빈 칸에 숫자가 들어갈수 있는지를 판단하는 issafe함수를 만들려고 했지만 쉽지 않았다.
// 나는 issafe 함수에서 3*3부분을 확인하는 코드가 굉장히 길게 나왔다.
// 그런데 다른 사람들이 작성한 코드를 보니 훨씬 짧게 작성이 되어 있었다. 
// 그 코드는 이해가 잘 안가서 일단 내가 써 놓은 코드로 사용을 했지만 다 풀고나서 그 코드로도 다시 작성을 해 보았다.

// #include<iostream>
// #include<vector>
// using namespace std;

// int sudoku[9][9]={0},zero=0,check=0;
// vector <pair<int,int>> v;

// bool issafe(int vx,int vy,int x){
//     for(int i=0;i<9;i++){
//         if(sudoku[vx][i]==x) // 가로 확인
//             return false;
//         if(sudoku[i][vy]==x) // 세로 확인
//             return false;
//     }
//     if(vx>=0&&vx<=2 && vy>=0&&vy<=2){ // 0, 0
//         for(int i=0;i<3;i++){ 
//             for(int j=0;j<3;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=0&&vx<=2 && vy>=3&&vy<=5){ // 0, 1
//         for(int i=0;i<3;i++){ 
//             for(int j=3;j<6;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=0&&vx<=2 && vy>=6&&vy<=8){ // 0, 2
//         for(int i=0;i<3;i++){ 
//             for(int j=6;j<9;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=3&&vx<=5 && vy>=0&&vy<=2){ // 1, 0
//         for(int i=3;i<6;i++){ 
//             for(int j=0;j<3;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=3&&vx<=5 && vy>=3&&vy<=5){ // 1, 1
//         for(int i=3;i<6;i++){ 
//             for(int j=3;j<6;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=3&&vx<=5 && vy>=6&&vy<=8){ // 1, 2
//         for(int i=3;i<6;i++){ 
//             for(int j=6;j<9;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=6&&vx<=8 && vy>=0&&vy<=2){ // 2, 0
//         for(int i=6;i<9;i++){ 
//             for(int j=0;j<3;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=6&&vx<=8 && vy>=3&&vy<=5){ // 2, 1
//         for(int i=6;i<9;i++){ 
//             for(int j=3;j<6;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     else if(vx>=6&&vx<=8 && vy>=6&&vy<=8){ // 2, 2
//         for(int i=6;i<9;i++){ 
//             for(int j=6;j<9;j++){
//                 if(sudoku[i][j]==x)
//                     return false;
//             }
//         }
//     }
//     return true;
// }

// void bt(int n){
//     if(zero==n){ // n이 zero와 같으면 모든 칸을 채웠다는 뜻이다.
//         check=1; // check를 1로 바꿔준다.
//         return;
//     }
//     int vx=v[n].first;
//     int vy=v[n].second;
//     for(int x=1;x<=9;x++){
//         if(issafe(vx,vy,x)==true){
//             sudoku[vx][vy]=x;
//             bt(n+1);
//         }
//         if(check==1) // check변수를 이용하여 끝난다는 것을 확인 시켜주지 않으면 제대로 실행이 되지 않았다.
//             return;
//     }
//     sudoku[vx][vy]=0;
//     return;
// }

// int main(){
//     int num;
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             cin>>num;
//             sudoku[i][j]=num;
//             if(sudoku[i][j]==0){
//                 zero++;
//                 v.push_back(make_pair(i,j));
//             }
//         }
//     }
//     cout<<zero<<"\n";
//     bt(0);
//     cout<<"\n";
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             cout<<sudoku[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }   

#include<iostream>
#include<vector>
using namespace std;

int sudoku[9][9]={0},zero=0,check=0;
vector <pair<int,int>> v;

bool issafe(int vx,int vy,int x){
    for(int i=0;i<9;i++){
        if(sudoku[vx][i]==x) // 가로 확인
            return false;
        if(sudoku[i][vy]==x) // 세로 확인
            return false;
    }
    int ax=(vx/3)*3;
    int ay=(vy/3)*3;
    for(int i=ax;i<ax+3;i++){
        for(int j=ay;j<ay+3;j++){
            if(sudoku[ax][ay]==x)
                return false;
        }
    }
    return true;
}

void bt(int n){
    if(zero==n){ // n이 zero와 같으면 모든 칸을 채웠다는 뜻이다.
        check=1; // check를 1로 바꿔준다.
        return;
    }
    int vx=v[n].first;
    int vy=v[n].second;
    for(int x=1;x<=9;x++){
        if(issafe(vx,vy,x)==true){
            sudoku[vx][vy]=x;
            bt(n+1);
        }
        if(check==1) // check변수를 이용하여 끝난다는 것을 확인 시켜주지 않으면 제대로 실행이 되지 않았다.
            return;
    }
    sudoku[vx][vy]=0;
    return;
}
int main(){
    int num;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>num;
            sudoku[i][j]=num;
            if(sudoku[i][j]==0){
                zero++;
                v.push_back(make_pair(i,j));
            }
        }
    }
    cout<<zero<<"\n";
    bt(0);
    cout<<"\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
}   