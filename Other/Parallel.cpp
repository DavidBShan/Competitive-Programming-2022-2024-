#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const long long MAX_N = 2e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const ll LINF = 1e18;

long long n, q, arr[MAX_N], st[4 * MAX_N];

void build(long long node, long long start, long long end) {
    if (start == end) {
        st[node] = arr[start];
        return;
    }
    long long mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    st[node] = st[2 * node] & st[2 * node + 1];
}

void update(long long node, long long start, long long end, long long idx, long long val) {
    if (start == end) {
        arr[idx] = val;
        st[node] = val;
        return;
    }
    long long mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    st[node] = st[2 * node] & st[2 * node + 1];
}

long long query(long long node, long long start, long long end, long long l, long long r) {
    if (start > r || end < l) return -1;
    if (l <= start && end <= r) return st[node];
    long long mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) & query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    for(long long i = 1, a, b; i <= q; i++){
        char op; cin >> op >> a >> b;
        if(op == 'Q'){
            long long andVal; cin >> andVal;
            long long print = andVal & query(1, 1, n, a, b);
            cout << print << "\n";
        }else{
            update(1, 1, n, a, b);
        }
    }
}