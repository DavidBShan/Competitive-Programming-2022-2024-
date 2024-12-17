#include <bits/stdc++.h>
using namespace std;

int main(){
    int C, mn = 2*10e5+5, ang = 0; cin >> C;
    for(int i = 0, temp; i < C; i++){
        cin >> temp;
        if(temp<mn){
            mn=temp;
            ang++;
        }
    }
    cout << ang;
}