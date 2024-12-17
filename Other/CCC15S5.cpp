#include <bits/stdc++.h>
using namespace std;
const long long MN = 3003;
const long long MM = 102;
long long N, M; long long a[MN], b[MM], dp[MN][MM][MM][2];

long long fun(long long i, long long l, long long r, long long bef){
    if(dp[i][l][r][bef] != -1) return dp[i][l][r][bef];
    long long ans = 0;
    if(i <= N){
        ans = max(ans, fun(i + 1, l, r, true));
        if(bef) ans = max(ans, a[i] + fun(i + 1, l, r, false));
    }
    if(l <= r){
        ans = max(ans, fun(i, l + 1, r, true));
        if(bef) ans = max(ans, b[r] + fun(i, l, r-1, false));
    }
    return dp[i][l][r][bef] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> N;
    for(long long i = 1; i <= N; i++) cin >> a[i];
    cin >> M;
    for(long long i = 1; i <= M; i++) cin >> b[i];
    sort(b, b + M + 1);
    cout << fun(1, 1, M, 1) << endl;
}