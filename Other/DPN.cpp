#include <bits/stdc++.h>
using namespace std;
const long long MM = 402;
long long n, dp[MM][MM], arr[MM], psa[MM];
long long fun(long long l, long long r){
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    long long ans = 1e18;
    for(long long i = l; i < r; i++){
        ans = min(ans, fun(l, i) + fun(i+1, r) + psa[r] - psa[l-1]);
    }
    return dp[l][r] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; memset(dp, -1, sizeof(dp)); memset(psa, 0, sizeof(psa));
    for(long long i = 1; i <= n; i++){
        cin >> arr[i]; psa[i] = psa[i-1] + arr[i];
    }
    cout << fun(1, n) << "\n";
}