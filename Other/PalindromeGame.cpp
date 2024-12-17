#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        string x; cin >> x;
        if(x[x.length()-1] == '0') cout << "E" << endl;
        else cout << "B" << endl;
    }
}