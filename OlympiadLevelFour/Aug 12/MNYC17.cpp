#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
long long aHash[MM], bHash[MM], p[MM], mod = 1e9+7;
int seed = 131; 

long long substrHash(int l, int r, long long hash[]){
    return (hash[r]-hash[l-1]*p[r-l+1]%mod + mod)%mod;
}

int main(){
    string A, B; cin >> A >> B; p[0] = 1;
    for(int i = 1; i <= A.size(); i++) aHash[i] = (aHash[i-1]*seed+A[i-1])%mod;
    for(int i = 1; i <= B.size(); i++) bHash[i] = (bHash[i-1]*seed+B[i-1])%mod;
    for(int i = 1; i <= MM; i++) p[i] = p[i-1]*seed % mod;
    for(int len = min(A.size(), B.size()); len >= 0; len--){
        long long hash1 = substrHash(A.size()-len+1, A.size(), aHash);
        long long hash2 = substrHash(1, len, bHash);
        if(hash1 == hash2){
            cout << A << B.substr(len) << endl;
            return 0;
        }
    }
    cout << A << B << endl;
}