#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+5;
struct node { long long v, lz; } seg[MM*4];
long long N, K, Q;

void push_up(long long rt){
    seg[rt].v = max(seg[rt*2].v, seg[rt*2+1].v);
}

void push_down(long long rt){
    seg[rt*2].v += seg[rt].lz; seg[rt*2+1].v += seg[rt].lz;
    seg[rt*2].lz += seg[rt].lz; seg[rt*2+1].lz += seg[rt].lz;
    seg[rt].lz = 0;
}

void update(long long l, long long r, long long ql, long long qr, long long val, long long rt){
    if(ql>r || qr<l) return;
    if(ql<=l && r<=qr){
        seg[rt].v += val; seg[rt].lz += val; return;
    }
    if(seg[rt].lz) push_down(rt);
    long long mid = (l+r)/2;
    update(l, mid, ql, qr, val, rt*2); update(mid+1, r, ql, qr, val, rt*2+1); push_up(rt);
}

long long query(long long l, long long r, long long ql, long long qr, long long rt){
    if(ql>r || qr<l) return 0;
    if(ql<=l && r<=qr) return seg[rt].v;
    if(seg[rt].lz) push_down(rt);
    long long mid = (l+r)/2;
    return max(query(l, mid, ql, qr, rt*2), query(mid+1, r, ql, qr, rt*2+1));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> Q;
    for(long long i = 0, op, x, y; i < N; i++){
        cin >> op >> x >> y;
        if(op == 0) update(0, N-1 , x-K+1, x, y, 1);
        else cout << query(0, N-1 , x, y, 1) << "\n";
    }
}