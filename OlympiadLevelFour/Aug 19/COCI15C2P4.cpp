#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6+5, mod = 1e9+7, base = 131;
long long pw[MM], hsh[MM];
int ans, N;
long long subHash(int L, int R) { return (hsh[R]-hsh[L-1]*pw[R-L+1] % mod + mod) % mod;}
map<int, int> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; pw[0] = 1;
    for(int i = 1; i < MM; i++)  pw[i] = pw[i-1]*base%mod;
    for(int i = 0; i < N; i++){
        string s; cin >> s; hsh[0] = 0;
        for(int j = 1; j <= s.length(); j++) hsh[j] = (hsh[j-1]*base+s[j-1])%mod;
        int mx = 0;
        for (int j = 1; j <= s.length(); j++){
            int val = subHash(1, j);
            if(val == subHash(s.length() - j + 1, s.length())){
                if(mp.count(val)) mx = max(mx, mp[val]);
            }
        }
        mp[hsh[s.size()]] = mx+1;
        ans = max(ans, mx+1); 
    }
    cout << ans;
}