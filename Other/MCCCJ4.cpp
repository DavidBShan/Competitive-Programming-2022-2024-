#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+5;
long long N, S, T, arr[MM], psa[MM];

long long sum(long long l, long long r){
    return psa[r]-psa[l-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S >> T;
    for(long long i = 1; i <= N; i++){
        cin >> arr[i]; psa[i] = psa[i-1]+arr[i];
    }
    long long ans = -1;
    if(S*T >= N){
        cout << sum(1, N) << "\n";
        return 0;
    }
    for(long long i = 0; i <= T; i++){
        //cout << sum(1, S*i) << " " << sum(N-((T-i)*S)+1, N) << "\n";
        ans = max(ans, sum(0, S*i) + sum(N-((T-i)*S)+1, N));
    }
    cout << ans << "\n";
}