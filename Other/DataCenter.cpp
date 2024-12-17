#include <bits/stdc++.h>
using namespace std;
int n, s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s; vector<int> a, b;
    a.resize(n); b.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i] = -a[i];
    }
    sort(a.begin(), a.end());
    for(int k = 1, m, c; k <= s; k++){
        cin >> m >> c;
        for (int i = 0; i < c; i++) a[i] += m;
        merge(a.begin(), a.begin()+c, a.begin()+c, a.end(), b.begin());
        swap(a,b);
    }
    for(int i = 0; i < n; i++) cout << -a[i] << " ";
}