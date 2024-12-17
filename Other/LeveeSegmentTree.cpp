#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll int

const int MAX_N = 3e7 + 5;
long long n, q, arr[MAX_N], st[MAX_N], sumST[MAX_N];
char temp;
long long ans = 0;

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        st[node] = val;
        sumST[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    st[node] = max(st[2 * node], st[2 * node + 1]);
    sumST[node] = sumST[2 * node] + sumST[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return -1e9;
    if (l <= start && end <= r) return st[node];
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

int sumQuery(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return 0;
    if (l <= start && end <= r) return sumST[node];
    int mid = (start + end) / 2;
    return sumQuery(2 * node, start, mid, l, r) + sumQuery(2 * node + 1, mid + 1, end, l, r);
}


void solve() {
    cin >> n >> q;
    for(int i = 1, a, b; i <= q; i++){
        cin >> temp >> a >> b;
        if(temp == 'C') update(1, 1, n, a ^ ans, b ^ ans);
        else if(temp == 'S'){
            ans = sumQuery(1, 1, n, a ^ ans, b ^ ans);
            cout << ans << "\n";
        }else{
            ans = query(1, 1, n, a ^ ans, b ^ ans);
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}