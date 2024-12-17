#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N; cin >> N; char s[2000005]; long long loc = 0, ans = 0;
    for(long long i = 0; i < 2*N; i++) cin >> s[i];
    for(long long i = 0; i < 2*N; i++){
        if(s[i] == 'I'){
            ans += abs(i-loc);
            loc+=2;
        }
    }
    cout << ans << "\n";
}