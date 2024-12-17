#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m; cin >> n >> m; map<string, long long> str;
    long long curCount = 1; vector<pair<long long, long long>> adj[n+1]; priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    for(long long i = 0; i < m; i++){
        string a, b; long long time; cin >> a >> b >> time;
        if(str.find(a) == str.end()){
            str[a] = curCount; curCount++;
        }
        if(str.find(b) == str.end()){
            str[b] = curCount; curCount++;
        }
        adj[str[a]].push_back({str[b], time});
    }
    long long q; cin >> q;
    for(long long i = 0; i < q; i++){
        string a, b; cin >> a >> b;
        long long dist[n+1]; fill(dist, dist+n+1, 1e12); dist[str[a]] = 0; pq.push({0, str[a]});
        while(!pq.empty()){
            long long u = pq.top().second; pq.pop();
            for(auto v : adj[u]){
                if(dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        if(dist[str[b]] == 1e12) cout << "Roger" << endl;
        else cout << dist[str[b]] << endl;
    }
}