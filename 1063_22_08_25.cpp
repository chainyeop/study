// 대각선 부분의 출력이 계속 이상하게 나와 시간을 많이 잡아먹었다. 원인을 찾는데 시간을 많이 허비했다.
// 알고보니 문제는 킹을 움직이고 나서 돌과 만났는지를 보는 코드인 if(mkx==sx && mky==sy) 부분에서 있었다.
// 대각선을 이동하는 부분에서는 코드가 두줄이지만 중괄호 없이 옆에다가만 적은게 화근이었다.

#include<iostream>
#include<string>
using namespace std;

bool issafe(int mkx,int mky,int msx,int msy){
    if(mkx<0 || mkx>7 || mky<0 || mky>7) return false;
    if(msx<0 || msx>7 || msy<0 || msy>7) return false;
    return true;
}

int main(){
    int board[8][8]={0},n;
    string K,S,C;
    cin>>K>>S>>n;
    int kx=K[0]-'A',ky=K[1]-'1',sx=S[0]-'A',sy=S[1]-'1';
    board[kx][ky]=1; // 킹의 현위치
    board[sx][sy]=1; // 돌의 현위치
    for(int i=0;i<n;i++){
        int mkx=kx,mky=ky,msx=sx,msy=sy; 
        cin>>C;
        if(C=="R"){ // 오른쪽 이동
            mkx++;
            if(mkx==sx && mky==sy) msx++; // 위치가 겹칠 경우 돌을 킹과 같은 방향으로 이동시킴
            if(issafe(mkx,mky,msx,msy)==true){ // 옮긴 위치가 범위 안일 경우 현위치를 바꿔줌
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        else if(C=="L"){ // 왼쪽 이동
            mkx--;
            if(mkx==sx && mky==sy) msx--; 
            if(issafe(mkx,mky,msx,msy)==true){
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        else if(C=="B"){ // 아래 이동
            mky--;
            if(mkx==sx && mky==sy) msy--; 
            if(issafe(mkx,mky,msx,msy)==true){
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        else if(C=="T"){ // 위 이동
            mky++;
            if(mkx==sx && mky==sy) msy++; 
            if(issafe(mkx,mky,msx,msy)==true){ 
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        if(C=="RT"){ // 오른쪽 위 이동
            mkx++; mky++;
            if(mkx==sx && mky==sy) {msx++; msy++;} // 이 부분에 중괄호를 넣었어야 했는데 빼먹은 것이 문제였다.
            if(issafe(mkx,mky,msx,msy)==true){
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        else if(C=="LT"){ // 왼쪽 위 이동
            mkx--; mky++;
            if(mkx==sx && mky==sy) {msx--; msy++;} 
            if(issafe(mkx,mky,msx,msy)==true){ 
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        else if(C=="RB"){ // 오른쪽 아래 이동
            mkx++; mky--;
            if(mkx==sx && mky==sy) {msx++; msy--;} 
            if(issafe(mkx,mky,msx,msy)==true){ 
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        else if(C=="LB"){ // 왼쪽 아래 이동
            mkx--; mky--;
            if(mkx==sx && mky==sy) {msx--; msy--;} 
            if(issafe(mkx,mky,msx,msy)==true){ 
                kx=mkx; ky=mky;
                sx=msx; sy=msy;
            }
        }
        //cout<<kx<<" "<<ky<<" "<<sx<<" "<<sy<<"\n";
        char akx=kx+'A',aky=ky+'1',asx=sx+'A',asy=sy+'1';
        cout<<akx<<aky<<"\n"<<asx<<asy<<"\n";
        C.clear();
    }
    char akx=kx+'A',aky=ky+'1',asx=sx+'A',asy=sy+'1';
    cout<<akx<<aky<<"\n"<<asx<<asy;
}
