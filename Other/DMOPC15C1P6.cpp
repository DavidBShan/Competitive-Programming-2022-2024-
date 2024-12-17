#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+5;
long long M, N, Q, a[MM];
struct node{
    long long sum, lz;
} seg[4*MM];

void push_down(long long l, long long r, long long cur){
    long long val = seg[cur].lz, mid = (l+r)/2, lc = 2*cur, rc = 2*cur + 1;
    seg[lc].sum = (seg[lc].sum + (mid - l + 1) * val % M) %M; seg[lc].lz = (seg[lc].lz + val)%M;
    seg[rc].sum = (seg[rc].sum + (r - mid) * val % M) %M; seg[rc].lz = (seg[rc].lz + val)%M;
    seg[cur].lz  = 0;
}

void build(long long l, long long r, long long cur){
    if(l == r){
        seg[cur].sum = a[l];
        seg[cur].lz = 0;
        return;
    }
    long long mid = (l+r)/2;
    build(l, mid, 2*cur); build(mid+1, r, 2*cur+1);
    seg[cur].sum = (seg[2*cur].sum + seg[2*cur+1].sum)%M;
}

void update(long long l, long long r, long long x, long long y, long long val, long long cur){
    if(l == x && r == y){
        seg[cur].sum = (seg[cur].sum + (r - l + 1) * val % M) %M;
        seg[cur].lz = (seg[cur].lz + val)%M;
        return;
    }else{
        if(seg[cur].lz) push_down(l, r, cur);
        long long mid = (l+r)/2;
        if(y <= mid){
            update(l, mid, x, y, val, 2*cur);
        }else if(x > mid){
            update(mid+1, r, x, y, val, 2*cur+1);
        }else{
            update(l, mid, x, mid, val, 2*cur);
            update(mid+1, r, mid+1, y, val, 2*cur+1);
        }
        seg[cur].sum = (seg[2*cur].sum + seg[2*cur+1].sum) % M;
    }
}

long long query(long long l, long long r, long long x, long long y, long long cur){
    if(r < x || l > y)return 0;
    if(x<=l && r<=y)return seg[cur].sum;
    if(seg[cur].lz) push_down(l, r, cur);
    long long mid = (l+r)/2;
    return (query(l, mid, x, y, 2*cur) + query(mid+1, r, x, y, 2*cur+1))%M;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> Q;
    for(long long i = 1; i <= N; i++) cin >> a[i];
    build(1, N, 1);
    for(long long i = 0; i < Q; i++){
        long long op, x, y; cin >> op >> x >> y;
        if(op == 1){
            long long v; cin >> v;
            update(1, N, x, y, v, 1);
        }else{
            cout << query(1, N, x, y, 1) << "\n";  
        }
    }
}