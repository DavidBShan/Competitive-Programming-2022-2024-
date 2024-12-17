#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int i = 0, a, b, c; i < T; i++){
        cin >> a >> b >> c;
        if((a+c)%2!=0) cout << "NO\n";
        else if(c>a) cout << "NO\n";
        else{
            int newB = b%2;
            if(newB == 0) cout << "YES\n";
            else if(c==0 && a == 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}