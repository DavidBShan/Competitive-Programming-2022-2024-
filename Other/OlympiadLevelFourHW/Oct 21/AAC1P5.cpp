#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
long long odd[MM], even[MM], dis[MM], N; vector<pair<long long, long long>> adj[MM];
void dfs(int cur, int pre){
    if(dis[cur]%2==0) even[cur]++;
    else odd[cur]++;
    for(auto [u, w]: adj[cur]){
        if(u==pre) continue;
        dis[u] = dis[cur]+w; dfs(u, cur);
        odd[cur] += odd[u]; even[cur] += even[u];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0, u, v, w; i < N-1; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    dfs(1, 0);
    long long ans = abs(2*odd[1]*even[1]-N*(N-1)/2); 
    for(int i = 1; i <= N; i++){
        long long tempEven = even[1]-even[i]+odd[i]; long long tempOdd = odd[1]-odd[i]+even[i];
        ans = min(ans, abs(2*tempEven*tempOdd-N*(N-1)/2));
    }
    cout << ans;
}