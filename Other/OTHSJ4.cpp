#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> power(n);
    for(int i=0; i<n; i++)
        cin >> power[i]; 
    sort(power.begin(), power.end());
    vector<long long> prefix(n+1, 0), suffix(n+1, 0);
    for(int i=1; i<=n; i++) {
        prefix[i] = prefix[i-1] + power[i-1];
        suffix[i] = suffix[i-1] + power[n-i];
    }
    long long maxPower = 0;
    for(int i=0; i<=k; i++) {
        if(i <= n) {
            long long powerDestroyed = prefix[i] + (i + k <= n ? suffix[k-i] : 0);
            maxPower = max(maxPower, powerDestroyed);
        }
    }

    cout << maxPower << endl;

    return 0;
}