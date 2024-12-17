#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int n, q; vector<int> a; vector<pi> ans;
void rev(int l, int r){
    reverse(a.begin()+l, a.begin()+r+1);
    ans.push_back({l, r});
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=0, x; i<n; i++){
        cin >> x;  a.push_back(x);
    }
    for(int i=1; i<n; i++) {
        int p = 0;
        while(p < i && a[p] < a[i]) p++;
        if(p < i ) {
            rev(p, i-1);
            rev(p, i);
        }
    }
    cout << ans.size() << "\n";
    for(auto [l, r] : ans)
        cout << l+1 << " " << r+1 << "\n";
}