#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
long long arr[MM], suf[MM], pref[MM], N, S, T, ans = 0;
unordered_set<long long>> vis;

long long rec(long long step, long long sufPointer, long long prefPointer, long long ans){
    if(sufPointer + prefPointer >= N) return ans;
    if(vis.find(sufPointer + prefPointer)==vis.end()) return -1;
    if(step == T) return ans;
    int sufSum = suf[sufPointer+S] - suf[sufPointer];
    int prefSum = pref[prefPointer+S] - pref[prefPointer];
    if(sufPointer + prefPointer + S > N) {
        return ans + (suf[N - prefPointer]-suf[sufPointer]);
    }
    int ans1 = rec(step+1, sufPointer+S, prefPointer, ans+sufSum);
    int ans2 = rec(step+1, sufPointer, prefPointer+S, ans+prefSum); 
    vis.insert(sufPointer + prefPointer);
    return max(ans1, ans2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S >> T;
    suf[0] = 0; pref[0] = 0;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++){
        suf[i] = suf[i-1] + arr[N-i+1];
        pref[i] = pref[i-1] + arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0, 0);
}