#include <bits/stdc++.h>
using namespace std;
const int MM = 405;
int N, dp[MM][MM], arr[MM], psa[MM], ans = -1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i]; psa[i] = psa[i-1] + arr[i];
        ans = max(ans, arr[i]); dp[i][i] = true;
    }
    for(int len = 1; len < N; len++){
        for(int l = 1, r = l + len; r <= N; l++, r++){
            for(int i = l, j = r;i < j;){
                if(dp[l][i] && dp[j][r] && (i+1 == j || dp[i+1][j-1]) && psa[i] - psa[l-1] == psa[r] - psa[j-1]){
                    dp[l][r] = true; break;
                }
                if(psa[i] - psa[l-1] < psa[r] - psa[j-1]) i++;
                else j--;
            }
            if(dp[l][r]) ans = max(ans, psa[r] - psa[l-1]);
        }
    }
    cout << ans;    
}