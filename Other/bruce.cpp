#include <bits/stdc++.h>
using namespace std;
vector<array<int, 3>> segment;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; int a[n+1], b[n+1];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0, val = -1;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(val!=b[i] && val!=-1){
            if(val!=-1){
                segment.push_back({l, r, val});
                l = i; r = i; val = b[i];
            }else val = b[i];
        } else {
            r = i;
            val = b[i];
        }
    }
    segment.push_back({l, r, val}); vector<pair<int, int>> lft, rit;
    for(int k =0, i = 0; k < segment.size(); k++){
        auto [l, r, val] = segment[k];
        while(i < n && a[i] != val) i++;
        if(i==n){ cout << "NO\n"; return 0;}
        if(l < i) lft.push_back({l, i});
        if(r > i) rit.push_back({i, r});
    }
    reverse(rit.begin(), rit.end());
    cout << "YES\n";
    cout << lft.size() + rit.size() << endl;
    for(auto [l, r]: lft) cout << "L " << l << " " << r << endl;
    for(auto [l, r]: rit) cout << "R " << l << " " << r << endl;
}
