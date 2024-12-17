#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> gaps;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (count > 0) {
                gaps.push_back(count);
            }
            count = 0;
        } else {
            count++;
        }
    }

    sort(gaps.begin(), gaps.end());

    while (k > 0 && !gaps.empty()) {
        if (k >= gaps.back()) {
            k -= gaps.back();
            gaps.pop_back();
        } else {
            break;
        }
    }

    cout << gaps.size() + 1 << "\n";

    return 0;
}