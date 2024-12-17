#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
struct node { int l, r, v;} seg[MM*4];
int N, Q, ans;

void build(int l, int r, int rt){
    seg[rt].l = l; seg[rt].r = r;
    if(l==r) {cin >> seg[rt].v; return;}
    int mid = (l+r)/2;
    build(l, mid, rt*2); build(mid+1, r, rt*2+1);
    seg[rt].v = min(seg[rt*2].v, seg[rt*2+1].v);
}

void update(int pos, int val, int rt){
    if(seg[rt].l==seg[rt].r) {seg[rt].v = val; return;}
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(pos<=mid) update(pos, val, rt*2);
    else update(pos, val, rt*2+1);
    seg[rt].v = min(seg[rt*2].v, seg[rt*2+1].v);
}

int query(int l, int r, int val, int rt){
    if(seg[rt].v >= val) return -1;
    if(seg[rt].l==seg[rt].r) return seg[rt].l;
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(r<=mid) return query(l, r, val, rt*2);
    if(l>mid) return query(l, r, val, rt*2+1);
    int lft = query(l, mid, val, 2*rt);
    return lft != -1?lft:query(mid+1, r, val, 2*rt+1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q; build(1, N, 1);
    for(int i = 1, op, x, y, z; i <= Q; i++){
        cin >> op >> x >> y; x^=ans; y^=ans;
        if(op==1) update(x, y, 1);
        else{
            cin >> z; z^=ans;
            cout << (ans = query(x, y, z, 1)) << "\n";
        }
    }
}