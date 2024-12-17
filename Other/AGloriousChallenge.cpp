#include <bits/stdc++.h>
using namespace std;

int maxAbsValExpr(vector<int>& arr) {
    int n = arr.size();
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        max1 = max(max1, arr[i] + i);
        min1 = min(min1, arr[i] + i);
        max2 = max(max2, arr[i] - i);
        min2 = min(min2, arr[i] - i);
    }
    return max(max1 - min1, max2 - min2);
}

int main() {
    int N; cin >> N; vector<int> arr;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    cout << maxAbsValExpr(arr) << endl;
    return 0;
}