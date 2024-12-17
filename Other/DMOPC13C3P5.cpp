#include <bits/stdc++.h>
using namespace std;
const long long MM = 155;
long long dp[155][105][305], v[155], t[155], c[155];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long M, U, R; cin >> M >> U >> R;
    for(long long i = 1; i <= R; i++){
        cin >> v[i] >> t[i] >> c[i];
    }
    for(long long i = 1; i <= R; i++){
        for(long long j = 0; j <= U; j++){
            for(long long k = 0; k <= M; k++){
                if(t[i]>k || c[i] > j) dp[i][j][k] = dp[i-1][j][k];
                else dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-c[i]][k-t[i]]+v[i]);
            }
        }
    }
    cout << dp[R][U][M] << "\n";
}