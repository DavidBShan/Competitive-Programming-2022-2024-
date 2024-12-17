#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e5 + 5, LOG = 18, nodes = (1 << LOG); ll tree[nodes * 2];
int a[MM], cnt[MM];
vector <int> vec;
map <int, int> compMap;
int comp[MM];

void update(int x, int val) {
	for(; x > 0; x /= 2) tree[x] += val;
}

int query(int x, ll val) {
	if(x >= nodes) return x - nodes;
	if(tree[x * 2] >= val) return query(x * 2, val);
	return query(x * 2 + 1, val - tree[x * 2]);
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
        cin >> a[i] >> cnt[i];
        vec.push_back(a[i]);
	}
	sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int height = 0;
	for(int i = 0; i < vec.size(); i++) {
		compMap[vec[i]] = height;
		comp[height] = vec[i];
		height++;
	}
	ll total = 0;
	for(int i = 0; i < n; i++) {
		total += cnt[i];
		update(compMap[a[i]] + nodes, cnt[i]);
		cout << comp[query(1, (total + 1) / 2)] << "\n";
	}
}
