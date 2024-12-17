#include <bits/stdc++.h>
using namespace std;

int R, C, ans=0;
string W;
vector<string> vec;

void dfs(int len, int x, int y, int dx, int dy, bool turned=false) {
	if (x < 0 || x >= R || y < 0 || y >= C) return;
	if (vec[x][y] != W[len]) return;
	if (len == W.size() - 1) {
		ans++; return;
	}
	dfs(len + 1, x + dx, y + dy, dx, dy, turned);
	if (!turned && len >= 1) {
		dfs(len + 1, x - dy, y + dx, -dy, dx, true);
		dfs(len + 1, x + dy, y - dx, dy, -dx, true);
	}
}

int main() {
	cin >> W >> R >> C;
	for (int i = 0; i < R; i++) {
		string temp = "";
		for (int j = 0; j < C; j++) {
			char c; cin >> c; temp += c;
		}
		vec.push_back(temp);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (vec[i][j] == W[0]) {
				dfs(0, i, j, -1, -1);
				dfs(0, i, j, -1, 0);
				dfs(0, i, j, -1, 1);
				dfs(0, i, j, 0, -1);
				dfs(0, i, j, 0, 1);
				dfs(0, i, j, 1, -1);
				dfs(0, i, j, 1, 0);
				dfs(0, i, j, 1, 1);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}