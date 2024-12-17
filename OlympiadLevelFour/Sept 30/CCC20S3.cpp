#include <bits/stdc++.h>
using namespace std;
string needle, haystack; int mod = 1e9+7, base1 = 131, base2 = 10007, needleArr[26], haystackArr[26]; long long hsh1[200005], pw1[200005], hsh2[200005], pw2[200005];
set<pair<long long, long long>> ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> needle >> haystack;
    for(int i = 0; i < needle.size(); i++) needleArr[needle[i]-'a']++;
    hsh1[0] = 0; pw1[0] = 1; hsh2[0] = 0; pw2[0] = 1;
    for(int i = 0; i < haystack.size(); i++){
        hsh1[i+1] = (hsh1[i]*base1 + haystack[i])%mod;
        pw1[i+1] = (pw1[i]*base1)%mod;
        hsh2[i+1] = (hsh2[i]*base2 + haystack[i])%mod;
        pw2[i+1] = (pw2[i]*base2)%mod;
    }
    for(int i = 0; i < haystack.size(); i++){
        haystackArr[haystack[i]-'a']++;
        if(i>=needle.size()) haystackArr[haystack[i-needle.size()]-'a']--;
        if(memcmp(needleArr, haystackArr, sizeof(needleArr))==0){
            ans.insert({(hsh1[i+1] - hsh1[i+1-needle.size()]*pw1[needle.size()]%mod+mod)%mod, (hsh2[i+1] - hsh2[i+1-needle.size()]*pw2[needle.size()]+mod)%mod});
        }
    }
    cout << ans.size();
}