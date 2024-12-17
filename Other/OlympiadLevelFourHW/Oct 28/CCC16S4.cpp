#include <bits/stdc++.h>
using namespace std;
const int MM = 402;
int N; int psa[MM+1]; bool dp[MM+1][MM+1]; int ans = -1;
int psaSum(int l, int r) {return psa[r] - psa[l-1];}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; psa[0] = 0;
    for(int i = 1, temp; i <= N; i++){
        cin >> temp; psa[i] = psa[i-1] + temp;
        ans = max(ans, temp); dp[i][i] = true;
    }
    for(int len = 2; len <= N; len++){
        for(int l = 1, r = l+len-1; r <= N; l++, r++){
            for(int p= l, q = r; p < q;){
                if(dp[l][p] && dp[q][r] && (p+1 == q || dp[p+1][q-1]) && psaSum(l, p) == psaSum(q, r)){
                    dp[l][r] = true; break;
                }
                if(psaSum(l, p) < psaSum(q, r)) p++;
                else q--;
            }
            if(dp[l][r]) ans = max(ans, psaSum(l, r));
        }
    }
    cout << ans << endl;
}