#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int maxAnd = 0;
    int minAnd = INT_MAX;
    for (int i = 0; i < N; i++) {
        maxAnd = max(maxAnd, arr[i]); 
        minAnd = minAnd & arr[i];
    }
    cout << maxAnd << " " << minAnd << "\n";
    return 0;
}