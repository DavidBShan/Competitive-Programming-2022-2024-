#include <bits/stdc++.h>
using namespace std;
const int MM = 305;
string s; int n, dp[MM][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s; n = s.size();
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 1; len < n; len++){
        for(int l = 0; l + len < n; l++){
            int r = l + len; dp[l][r] = 1e9;
            if(s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']') dp[l][r] = dp[l+1][r-1];
            for(int i = l; i < r; i++) dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r]);
        }
    }
    cout << dp[0][n-1] << "\n";
}