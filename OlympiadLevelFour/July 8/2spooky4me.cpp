#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, L, S, a, b, s, count = 0, spooky = 0;
    cin >> N >> L >> S;
    vector<pair<int, int>> houses;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> s;
        houses.push_back({a,s}); houses.push_back({b+1, -s});
    }
    sort(houses.begin(), houses.end());
    spooky = houses[0].second;
    for(int i = 1; i < houses.size(); i++){
        if(spooky >= S) count+= houses[i].first-houses[i-1].first;
        spooky +=houses[i].second;
    }
    cout << L-count;
}