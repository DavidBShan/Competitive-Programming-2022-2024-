#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+3;
long long N, bit[MM], a[MM], h[MM],dp[MM];
void upd(long long pos, long long val){
    for(long long i = pos; i < MM; i+=i&-i) bit[i] = max(bit[i], val);
}
long long qry(long long pos){
    long long ret = 0;
    for(long long i = pos; i; i-=i&-i) ret = max(ret, bit[i]);
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    for(int i = 1; i <= N; i++) cin >> h[i];
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++){
        dp[i] = qry(h[i]-1) + a[i];
        upd(h[i], dp[i]);
    }
    cout << *max_element(dp+1, dp+N+1);
}