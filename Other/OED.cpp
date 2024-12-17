#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n; cin >> n; long long a[n+3]; long long ans = 0;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    long long changeTo = a[1];
    for(long long i = 2; i <= n; i++){
        int change = a[i]-changeTo;
        for(long long j = i; j <= n; j+=i){
            a[j] -= change;
        }
        ans+=abs(change);
    }
    cout << ans << "\n";
    return 0;
}