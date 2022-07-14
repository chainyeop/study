#include <iostream>
using namespace std;
int main(){
    int T, A, B, num1, num2, r;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        cin>>A>>B;
        num1=A;
        num2=B;
        while (B != 0)
        {
            r = A % B;
            A = B;
            B = r;
        }
        cout<<num1/A * num2/A * A<<endl;
    }
}
