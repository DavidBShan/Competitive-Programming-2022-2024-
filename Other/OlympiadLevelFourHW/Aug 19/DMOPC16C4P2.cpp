#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int B, F, f[MM], e[MM], p[MM], t[MM]; long long ans = 0; vector <int> vec;
	cin >> B;
	for (int i = 0; i < B; i++) cin >> f[i] >> e[i] >> p[i];
	cin >> F;
	for (int i = 0; i < F; i++) { cin >> t[i]; vec.push_back(t[i]); }
	sort(vec.begin(), vec.end());
	for (int i = 0; i < B; i++) {
		int upper = lower_bound(vec.begin(), vec.end(), f[i]) - vec.begin();
		int lower = upper_bound(vec.begin(), vec.end(), e[i]) - vec.begin() - 1;
		if (lower < upper) ans += p[i];
	}
	cout << ans;
}