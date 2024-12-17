#include <bits/stdc++.h>
using namespace std;

struct Node {
    int preOn, sufOn, mxOn, preOff, sufOff, mxOff, len;
}tree[ 200005 * 4 ];

Node combine(Node l, Node r) {
    Node res;
    res.len = l.len + r.len;
    res.preOn = (l.preOn == l.len) ? l.len + r.preOn : l.preOn;
    res.sufOn = (r.sufOn == r.len) ? r.len + l.sufOn : r.sufOn;
    res.mxOn = max({l.mxOn, r.mxOn, l.sufOn + r.preOn});
    res.preOff = (l.preOff == l.len) ? l.len + r.preOff : l.preOff;
    res.sufOff = (r.sufOff == r.len) ? r.len + l.sufOff : r.sufOff;
    res.mxOff = max({l.mxOff, r.mxOff, l.sufOff + r.preOff});
    return res;
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[v].preOff = tree[v].sufOff = tree[v].mxOff ^= 1;
        tree[v].preOn = tree[v].sufOn = tree[v].mxOn ^= 1;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v * 2, tl, tm, pos);
        else update(v * 2 + 1, tm + 1, tr, pos);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) return Node();
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].len = 1;
        tree[v].preOff = tree[v].sufOff = tree[v].mxOff = 1;
        tree[v].preOn = tree[v].sufOn = tree[v].mxOn = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    build(1, 1, n);
    for(int i = 1; i <= q; i++) {
        string type; cin >> type;
        if (type == "TOGGLE") {
            int x; cin >> x;
            update(1, 1, n, x);
        } else if(type == "ON") {
            int l, r; cin >> l >> r;
            Node ans = query(1, 1, n, l, r);
            cout << ans.mxOn << "\n";
        }else{
            int l, r; cin >> l >> r;
            Node ans = query(1, 1, n, l, r);
            cout << ans.mxOff << "\n";
        }
    }
}
