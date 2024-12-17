#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long ans = 0; string s; cin >> s;
    for(int i = 0; i < s.size(); i++){
        ans = ans*26 + (s[i]-'A'+1);
    }
    cout << ans;
}