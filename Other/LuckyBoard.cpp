#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<tuple<long long, long long, int>> v;
    for(int i = 1; i <= N; i++){
        long long x, y;
        cin >> x >> y;
        v.push_back({x, y, i}); 
    }
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return get<0>(a) * get<1>(b) > get<0>(b) * get<1>(a) || 
               (get<0>(a) * get<1>(b) == get<0>(b) * get<1>(a) && get<2>(a) < get<2>(b));
    });
    for(int i = 0; i < N; i++){
        cout << get<2>(v[i]) << " "; 
    }
}