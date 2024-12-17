#include <bits/stdc++.h>
using namespace std;
const long long MM = 205, mod = 100000;
long long N, dp[MM][MM]; string s, opens = "([{", closes = ")]}";
long long options(long long l, long long r){
    if(s[l] == '?' && s[r] == '?') return 3;
    long long fl = opens.find(s[l]), fr = closes.find(s[r]);
    if((fl == fr && fl!=-1) || (s[l]=='?' && fr!=-1) || (fl!=-1 && s[r]=='?')) return 1;
    return 0;
}

long long fun(long long l, long long r){
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    long long ans = 0;
    for(long long i = l + 1; i <= r; i+=2){
        ans+=options(l, i)*fun(i+1, r) * fun(l+1, i-1);
        if(ans >= mod) ans = ans % mod + mod;
    }
    return dp[l][r] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s; memset(dp, -1, sizeof(dp));
    long long ans = fun(0, N-1);
    if(ans >= mod) cout << setfill('0') << setw(5) << ans % mod << "\n";
    else cout << ans << "\n";
}