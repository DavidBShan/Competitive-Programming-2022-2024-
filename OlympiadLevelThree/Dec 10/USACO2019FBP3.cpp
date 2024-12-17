
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e9;

int main() {
	int N; cin >> N; string query[N]; int minV[N]; int maxV[N];
	for (int m = 0; m < N; m++) {
		cin >> query[m] >> minV[m] >> maxV[m];
	}
	int low = -MM;
	int high = MM;
	for (int m = N - 1; m >= 0; m--) {
		if (query[m] == "none") {
			low = max(low, minV[m]);
			high = min(high, maxV[m]);
		} else if (query[m] == "off") {
			low += minV[m];
			high += maxV[m];
		} else if (query[m] == "on") {
			low -= maxV[m];
			high -= minV[m];
			low = max(0, low);
		}
	}
	cout << low << ' ' << high << endl;

	low = -MM;
	high = MM;
	for (int m = 0; m < N; m++) {
		if (query[m] == "none") {
			low = max(low, minV[m]);
			high = min(high, maxV[m]);
		} else if (query[m] == "on") {
			low += minV[m];
			high += maxV[m];
		} else if (query[m] == "off") {
			low -= maxV[m];
			high -= minV[m];
			low = max(0, low);
		}
	}
	cout << low << ' ' << high << endl;
}