#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+3, mod = 1e9 + 7, base = 131;
long long findHash;
long long hsh[MM], power[MM];
int main(){
    string org, find; cin >> org >> find;
    hsh[0] = 0; power[0] = 1;
    for(char c : find) findHash = (findHash * base + c) % mod;
    for(int i = 1; i <= org.size(); i++){
        hsh[i] = (hsh[i-1]*base+org[i-1])%mod;
        power[i] = power[i-1] * base % mod;
    }
    for(int i=find.size(); i<=org.size(); i++){
        long long sub = (hsh[i] - hsh[i-find.size()] * power[find.size()] % mod + mod)%mod;
        if(sub == findHash) {
            cout << i - find.size() << "\n"; return 0;
        }
    }
    cout << -1 << "\n";
}