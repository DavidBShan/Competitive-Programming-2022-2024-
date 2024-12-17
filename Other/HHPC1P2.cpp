#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, Q; cin >> N >> Q; long long arr[N+1]; long long prefixDif[N+1]; long long prefixLast[N+1];
    map<long long, long long> lastPos;
    for(long long i = 1; i <= N; i++) cin >> arr[i];
    arr[0] = arr[1]-1; prefixDif[0] = 0; prefixLast[0] = 0;
    if(N == 1) {cout << "NO" << endl; return 0;}
    for(long long i = 1; i <= N; i++){
        prefixDif[i] = prefixDif[i-1] + (arr[i-1]==arr[i]?0:1);
        lastPos[arr[i]] = i;
        if(lastPos.count(-1*arr[i]) == 0) prefixLast[i] = prefixLast[i-1];
        else prefixLast[i] = max(prefixLast[i-1],lastPos[-1*arr[i]]);
    }
    for(int i = 0; i < Q; i++){
        long long l, r; cin >> l >> r;
        if(prefixDif[r] - prefixDif[l] == 0) cout << "YES\n";
        else if(prefixLast[r] >= l) cout << "YES\n";
        else cout << "NO\n";
    }
}