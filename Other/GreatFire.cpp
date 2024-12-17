#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e5+5;
long long N, M; vector<array<long long, 3>> event; vector<long long> rk; long long bit1[2*MM], bit2[2*MM], ans[MM], sol = 0;

void update(long long bit[], long long pos, long long val){
    for(long long i = pos + 1; i < 2*MM; i+=i&-i) bit[i] = min(bit[i], val);
}

long long qry(long long bit[], long long pos){
    long long sum = 1e18;
    for(long long i = pos + 1; i > 0; i-=i&-i) sum = min(sum, bit[i]);
    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(long long i = 1, x, y; i <= N; i++){
        cin >> x >> y; event.push_back({x, y, i}); rk.push_back(y);
    }
    cin >> M;
    for(long long i = 1, x, y; i <= M; i++){
        cin >> x >> y; event.push_back({x, y, 0}); rk.push_back(y);
    }
    sort(rk.begin(), rk.end()); rk.resize(unique(rk.begin(), rk.end()) - rk.begin());
    long long sz = rk.size();
    for(auto &[x, y, v] : event) y = lower_bound(rk.begin(), rk.end(), y) - rk.begin();
    sort(event.begin(), event.end()); memset(bit1, 0x3f, sizeof bit1); memset(bit2, 0x3f, sizeof bit2);
    for(auto [x, y, v] : event){
        if(v == 0){ update(bit1, y, -x-rk[y]); update(bit2, sz-y, -x+rk[y]); }
        else{ ans[v]  = min(x+rk[y]+qry(bit1, y) , x-rk[y]+qry(bit2, sz-y)); }
    }
    reverse(event.begin(), event.end()); memset(bit1, 0x3f, sizeof bit1); memset(bit2, 0x3f, sizeof bit2);
    for (auto [x, y, v] : event) {
        if (v == 0) { update(bit1, y, x - rk[y]); update(bit2, sz - y, x + rk[y]); }
        else { ans[v] = min(ans[v], min(-x + rk[y] + qry(bit1, y), -x - rk[y] + qry(bit2, sz-y))); }
    }
    for(long long i = 1; i <= N; i++) sol += ans[i];
    cout << sol;
}