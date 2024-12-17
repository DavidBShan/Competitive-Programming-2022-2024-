#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N; int ans;
    if(N%3==2){
        cout << 2*(N/3)<<endl;
        cout << "M_";
        for(int i = 0; i < N/3;i++){
            cout << "MM_";
        }
    }
    else if(N%3==1){
        cout << 2*(N/3)<<endl;
        cout << "_";
        for(int i = 0; i < N/3;i++){
            cout << "MM_";
        }
    } else{
        cout << 2*(N/3)<<endl;
        for(int i = 0; i < N/3;i++){
            cout << "_M_";
        }
    }
}