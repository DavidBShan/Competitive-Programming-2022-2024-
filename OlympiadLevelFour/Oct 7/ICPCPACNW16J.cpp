#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, LOG = log2(MM);
int N, Q; ll st[MM][LOG+1], val;
ll rmq(int l, int r){
    int k = log2(r - l + 1);
    return min(st[l][k], st[r-(1<<k)+1][k]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> st[i][0];
    for(int k=1; k<=LOG; k++)
        for(int i=1; i+(1<<k)-1 <= N; i++)
            st[i][k] = min(st[i][k-1], st[i+(1<<k-1)][k-1]);
    for(int k=1, l, r; k<=Q; k++){
        cin >> val >> l >> r;
        while(val && l <= r) {
            int lo = l, hi = r, pos = r+1;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(rmq(lo, mid) <= val) { pos = mid; hi = mid - 1;}
                else lo = mid + 1;
            }
            if(pos <= r) { val %= st[pos][0]; l = pos + 1; }
            else break;
        }
        cout << val << "\n";
    }
}