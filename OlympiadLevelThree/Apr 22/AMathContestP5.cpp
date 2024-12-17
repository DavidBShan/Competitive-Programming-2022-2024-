#include <bits/stdc++.h>
using namespace std;
const int MM = 10;
int dp[MM][MM][MM];
int main(){
    int N, ans = 0; cin >>  N;
    for(int i = 1; i < N;i++){
        dp[i][i][1] = 1;
    }
    for(int len = 1;len <= N;len++){
        for(int l = len, r = l+len; r<=N; l++, r++){
            for(int m=l+2; m < r-1; m++){
                dp[l][r][len] = max(dp[l][r][len], (dp[l][m][len-1] + dp[m][r][len-1]+1)%1000000007);
            }
        }
    }
    for(int i = 1; i < N;i++){
        ans = (ans + dp[ans][N][ans])%1000000007;
    }
    cout << ans;
}