#include <bits/stdc++.h>
using namespace std;
long long N, C;
long long dp[101][100001][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> C;
    for(long long i = 1, a, b, c, d; i <= N; i++){
        cin >> a >> b >> c >> d;
        for(long long j = 1; j <= C; j++){
            dp[i][j][0] =  max(dp[i-1][j][0], dp[i-1][j][1]);
            dp[i][j][1] =  max(dp[i-1][j][0], dp[i-1][j][1]);
            if(j >= a) dp[i][j][0] = max(dp[i][j][0], dp[i][j-a][1] + b);
            if(j >= c) dp[i][j][1] = max(dp[i][j][1], dp[i][j-c][0] + d);
        }
    }
    cout << max(dp[N][C][0], dp[N][C][1]);
}