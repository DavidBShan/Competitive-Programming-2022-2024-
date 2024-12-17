#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, bit[MM], ans; vector<pair<int, int>> a;
void update(int pos, int val){
    for(int i=pos+1; i<MM; i+=i&-i) bit[i] += val;
}
int query(int pos){
    int ret = 0;
    for(int i=pos+1; i>0; i-=i&-i) ret += bit[i];
    return ret;
}
int main(){
    cin >> n;
    for(int i=0, x; i<n; i++) {
        cin >> x;  a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++) {
        update(a[i].second, 1);
        ans = max(ans, i+1 - query(i));
    }
    cout << (ans > 0? ans : 1) << "\n";
}