//find kth number
//binary search it
//idea to find kth number from seg tree
//check if current root node has enough? if no AC
//check if left child if left child has enough buggy lines? if so go to left child query
//otherwise go to right child (k-left child's buggy lines)
//get answer when we reach leaf node

#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+2;
long long N, Q, L; long long v[4*MM], lz[4*MM];

void build(long long l, long long r, long long node){
    if(l == r){
        v[node] = 1; lz[node] = 0;
        return;
    }
    long long m = (l+r)/2;
    build(l, m, 2*node); build(m+1, r, 2*node+1);
    v[node] = v[2*node] + v[2*node+1];
}

void push_down(long long rt, long long l, long long r){
    int lc = 2*rt, rc = 2*rt+1, m = (l+r)/2;
    v[lc] = (m-l+1)-v[lc]; 
    v[rc] = (r-m)-v[rc];
    lz[lc]^=1; lz[rc]^=1;
    lz[rt] = 0;
}

long long query(long long l, long long r, long long k, long long rt){
    if(l==r) return l;
    if(lz[rt]) push_down(rt, l, r);
    long long m = (l+r)/2;
    if(v[2*rt] < k) return query(m+1, r, k-v[2*rt], 2*rt+1);
    else return query(l, m, k, 2*rt);
}

void update(long long l, long long r, long long x, long long y, long long rt){
    if(l==x && y == r){ v[rt] = r-l+1-v[rt]; lz[rt]^=1; return;}
    if(lz[rt]) push_down(rt, l, r);
    long long m = (l+r)/2;
    if(y<=m) update(l, m, x, y, 2*rt);
    else if(x>m) update(m+1, r,x , y, 2*rt+1);
    else update(l, m, x, m, 2*rt), update(m+1, r, m+1, y, 2*rt+1);
    v[rt] = v[2*rt] + v[2*rt+1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q >> L;
    build(1, N, 1);
    for(long long i = 1, x, y; i<=Q; i++){
        cin >> x >> y;
        update(1, N, x, y, 1);
        if(v[1] < L) cout << "AC?\n";
        else cout << query(1, N, L, 1) << endl;
    }
}