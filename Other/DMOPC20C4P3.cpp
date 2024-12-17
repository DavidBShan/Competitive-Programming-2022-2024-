#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 4e5 + 5;
long long ft[MAXN];
vector<tuple<long long, long long, long long>> events;
vector<long long> ys;

long long LSOne(long long x) {
    return x & (-x);
}

void update(long long x, long long v) {
    for (; x < MAXN; x += LSOne(x))
        ft[x] += v;
}

long long sum(long long x) {
    long long res = 0;
    for (; x; x -= LSOne(x))
        res += ft[x];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long N, M; cin >> N >> M;
    for(long long i = 1; i <= N; i++){
        long long x, y; cin >> x >> y;
        events.push_back({x, 1, y});
        ys.push_back(y);
    }
    for(long long i = 1; i <= M; i++){
        long long x, y; cin >> x >> y;
        events.push_back({x, 0, y});
        ys.push_back(y);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for(auto& e : events) {
        long long x, type, y;
        tie(x, type, y) = e;
        y = lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
        get<2>(e) = y;
        if(type == 1) {
            update(y, 1);
        }
    }
    sort(events.begin(), events.end());
    long long ans = 0;
    for(auto e : events) {
        long long x, type, y;
        tie(x, type, y) = e;
        if(type == 1) {
            update(y, -1);
        } else {
            ans += sum(y);
        }
    }
    cout << ans << endl;
    return 0;
}