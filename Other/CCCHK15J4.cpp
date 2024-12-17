#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long L, N; cin >> L >> N; vector<long long> length; vector<pair<long long,long long>> animal;
    for(long long i = 0; i < N; i++){
        long long x, y; cin >> x >> y; animal.push_back({x, y});
    }
    sort(animal.begin(), animal.end());
    long long prev_end = 0;
    for(long long i = 0; i < animal.size(); i++){
        if(animal[i].first > prev_end){
            length.push_back(animal[i].first - prev_end);
        }
        prev_end = max(prev_end, animal[i].second);
    }
    length.push_back(L - prev_end);
    sort(length.begin(), length.end());
    if(length[length.size()-1] < 0) cout << 0;
    else cout << length[length.size()-1];
}