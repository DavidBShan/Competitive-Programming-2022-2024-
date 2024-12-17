#include <bits/stdc++.h>
using namespace std;
vector<int> parent, sze;
int find(int x) {
    if (parent[x] == x) return x; 
    else return parent[x] = find(parent[x]);
}

void union_(int x, int y) {
    int px = find(x); int py = find(y);
    if (px != py) {
        parent[px] = py;
        sze[py] += sze[px];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    sze.resize(n+1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        union_(a, b);
    }
    int mx = 0;
    for(int i = 0; i < sze.size(); i++){
        mx = max(mx, sze[i]);
    }
    cout << mx;
}