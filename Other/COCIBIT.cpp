#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+5;
long long N, a[MM], v[MM]; long long tot, bit[MM]; vector<long long> comp;

void upd(long long pos, long long val){
    for(long long k = pos; k <= N; k+=k&-k) bit[k]+=val;
}

int findK(long long lmt){
    int ans = 0; long long sum = 0;
    for(int k = 18; k>=0; k--){
        ans += (1<<k);
        if(ans > N || sum + bit[ans] >= lmt) ans -= (1<<k);
        else sum+=bit[ans];
    }
    return ans+1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(long long i = 1; i <=N; i++){
        cin >> v[i] >> a[i]; comp.push_back(v[i]);
    }
    sort(comp.begin(), comp.end()); comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for(long long i = 1; i <= N; i++){
        long long p = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin() + 1;
        upd(p, a[i]);  tot+=a[i];
        p = findK((tot+1)/2);
        cout << comp[p-1] << "\n";
    }
}