#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3, LOG = 20;
int a[MM], len[MM], last[MM], st[LOG][MM], rit[MM];
int rmq(int l, int r){
    int k = log2(r - l + 1);
    return max(st[k][l], st[k][r - (1<<k) + 1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        len[i] = min(len[i-1]+1, i - last[a[i]]);
        last[a[i]] = i; st[0][i] = len[i];
    }
    fill(last, last+MM, N+1);
    for(int i = N-1; i >=0; i--){
        rit[i] = min(rit[i+1]+1, last[a[i]] - i);
        last[a[i]] = i;
    }
    for(int k = 0; k < LOG; k++){
        for(int i = 0; i+(1<<k)-1 <=N; i++){
            st[k][i] = max(st[k-1][i], st[k-1][i+(1<<k-1)]);
        }
    }
    #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3, LOG = 20;
int N, Q, a[MM], last[MM], len[MM], rit[MM], st[LOG][MM];
int rmq(int l, int r){
    int k = log2(r - l + 1);
    return max(st[k][l], st[k][r - (1<<k) + 1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) {
        cin >> a[i];
        len[i] = min(len[i-1]+1, i - last[a[i]]); //rightmost occurence of recurring value on the left
        last[a[i]] = i; st[0][i] = len[i]; //precompute that for RMQ
    }
    fill(last, last+MM, N+1);
    for(int i=N; i>=1; i--) {
        rit[i] = min(rit[i+1]+1, last[a[i]] - i); //leftmost occurence of recurring value on the right
        last[a[i]] = i;
    }
    for(int k=1; k<LOG; k++)
        for(int i=1; i+(1<<k)-1 <=N; i++)
            st[k][i] = max(st[k-1][i], st[k-1][i+(1<<k-1)]);
    for(int i=1, ans = 0, l, r; i<=Q; i++){
        cin >> l >> r;   l^=ans;  r^=ans;
        int ed = l + rit[l] - 1;   // location of next l value to the right
        cout << (ans = rmq(r, ed)) << "\n";
    }
}#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3, LOG = 20;
int N, Q, a[MM], last[MM], len[MM], rit[MM], st[LOG][MM];
int rmq(int l, int r){
    int k = log2(r - l + 1);
    return max(st[k][l], st[k][r - (1<<k) + 1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) {
        cin >> a[i];
        len[i] = min(len[i-1]+1, i - last[a[i]]); //rightmost occurence of recurring value on the left
        last[a[i]] = i; st[0][i] = len[i]; //precompute that for RMQ
    }
    fill(last, last+MM, N+1);
    for(int i=N; i>=1; i--) {
        rit[i] = min(rit[i+1]+1, last[a[i]] - i); //leftmost occurence of recurring value on the right
        last[a[i]] = i;
    }
    for(int k=1; k<LOG; k++)
        for(int i=1; i+(1<<k)-1 <=N; i++)
            st[k][i] = max(st[k-1][i], st[k-1][i+(1<<k-1)]);
    for(int i=1, ans = 0, l, r; i<=Q; i++){
        cin >> l >> r;   l^=ans;  r^=ans;
        int ed = l + rit[l] - 1;   // location of next l value to the right
        cout << (ans = rmq(r, ed)) << "\n";
    }
}
}