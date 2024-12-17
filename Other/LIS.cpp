#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> dp;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }
    cout << dp.size() << "\n";
}