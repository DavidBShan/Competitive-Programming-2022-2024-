#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int N, M, K, par[MM], vis[MM]; pair<int, int> arr[MM]; vector<int> lb, tr; unordered_map<int, int> mp[MM];
int fd(int d){ return d==par[d]? par[d]: par[d]=fd(par[d]); }
void join(int x, int y){ par[fd(x)] = fd(y); }
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        int x, y; cin >> x >> y;
        arr[i] = {x, y}; 
    }
    for(int i = 0; i < K; i++) par[i] = i;
    sort(arr, arr+K);
    for(int i = 0; i < K; i++){
        if(i > 0 && arr[i-1].second + 1 == arr[i].second) join(i-1, i);
        int pre = arr[i].first-1;
        for(int dy = -1; dy <= 1; dy++)
            if(mp[pre].count(arr[i].second+dy)) join(mp[pre][arr[i].second+dy], i);
        mp[arr[i].first][arr[i].second] = i;
        if(arr[i].first == 1 || arr[i].second == M) lb.push_back(i);
        if(arr[i].first == N || arr[i].second == 1) tr.push_back(i);
    }
    for(int x: lb) vis[fd(x)] = 1;
    for(int x: tr) {
        if(vis[fd(x)]) { cout << "NO\n"; return 0; }
    }
    cout << "YES\n";
}