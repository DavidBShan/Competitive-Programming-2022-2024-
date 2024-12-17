#include <bits/stdc++.h>
using namespace std;
const long long base = 131, mod = 1e9+7, MM = 1e6+5;
long long mainHash[MM], power[MM];
long long subHash = 0;
int main(){
    string mainStr, subStr; cin >> mainStr >> subStr;
    for(long long i = 0; i < subStr.size(); i++) subHash = (subHash*base + subStr[i]) % mod;
    mainHash[0] = 0; power[0] = 1;
    for(long long i = 1; i <= mainStr.size(); i++){
        mainHash[i] = (mainHash[i-1]*base%mod+mainStr[i-1])%mod;
        power[i] = power[i-1]*base%mod;
    }
    long long count = 0;
    for(long long i = subStr.size(); i <= mainStr.size(); i++){
        //cout << (char) mainHash[i];
        long long partMain = (mainHash[i]-mainHash[i-subStr.size()]*power[subStr.size()]%mod+mod)%mod;
        if(partMain==subHash) count++;
    }
    cout << count;
}   