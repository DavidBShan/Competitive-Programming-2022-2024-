#include <bits/stdc++.h>
using namespace std;
const long long MM = 3005;
long long N, dp[MM][MM], psa[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; 
    for(long long i = 1; i <= N; i++){
        cin >> dp[i][i]; psa[i] = psa[i-1] + dp[i][i];
    }
    for(long long len = 1; len < N; len++){
        for(long long l = 1, r = l + len; r <= N; l++, r++){
            dp[l][r] = psa[r] - psa[l-1] - min(dp[l+1][r], dp[l][r-1]);
        }
    }
    cout << 2*dp[1][N] - psa[N]<< "\n";
}