#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+2;
long long N, Q; long long v[4*MM], lz[4*MM];
void build(long long l, long long r, long long node){
    if(l == r){
        cin >> v[node]; lz[node] = 0;
        return;
    }
    long long m = (l+r)/2;
    build(l, m, 2*node); build(m+1, r, 2*node+1);
    v[node] = min(v[2*node], v[2*node+1]);
}
void push_down(long long rt){
    v[2*rt] = max(0LL, v[2*rt]-lz[rt]);
    v[2*rt+1] = max(0LL, v[2*rt+1]-lz[rt]);
    lz[2*rt]+=lz[rt]; lz[2*rt+1]+=lz[rt]; lz[rt] = 0;

}

long long query(long long l, long long r, long long x, long long y, long long rt){
    if(l==x && y == r) return v[rt];
    if(lz[rt]) push_down(rt);
    long long m = (l+r)/2;
    if(y<=m) return query(l, m, x, y, 2*rt);
    else if(x>m) return query(m+1, r, x, y, 2*rt+1);
    else return min(query(l, m, x, m, 2*rt), query(m+1, r, m+1, y, 2*rt+1));
}

void update(long long l, long long r, long long x, long long y, long long z, long long rt){
    if(l==x && y == r){ v[rt] = max(0LL, v[rt]-z); lz[rt]+=z; return;}
    if(lz[rt]) push_down(rt);
    long long m = (l+r)/2;
    if(y<=m) update(l, m, x, y, z, 2*rt);
    else if(x>m) update(m+1, r,x , y, z, 2*rt+1);
    else update(l, m, x, m, z, 2*rt), update(m+1, r, m+1, y, z, 2*rt+1);
    v[rt] = min(v[2*rt], v[2*rt+1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    build(1, N, 1);
    for(long long i = 1, x, y, z; i<=Q; i++){
        cin >> x >> y >> z;
        update(1, N, x, y, z, 1);
        cout << query(1, N, x, y, 1) << " " << v[1] << "\n";
    }
}