#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+5;
long long N, avg, arr[MM], dif[MM];
vector<long long> adj[MM];
vector<tuple<long long, long long, long long>> order;

void dfsBuild(long long cur, long long par){
    dif[cur] = arr[cur] - avg;
    for(long long v: adj[cur]){
        if(v == par) continue;
        dfsBuild(v, cur);
        dif[cur] += dif[v];
    }
}

void distribute(long long cur, long long par){
    for(long long v: adj[cur]){
        if(v == par) continue;
        if(dif[v] >= 0) distribute(v, cur);
        if(dif[v] > 0) order.push_back({v, cur, dif[v]});
    }

    for(long long v: adj[cur]){
        if(v == par || dif[v] >= 0) continue;
        order.push_back({cur, v, -dif[v]});
        distribute(v, cur);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(long long i = 0, temp; i < N; i++){
        cin >> arr[i]; avg += arr[i];
    }
    avg /= N;
    for(long long i = 0; i < N-1; i++){
        long long u, v; cin >> u >> v;
        --u, --v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfsBuild(0, -1);
    distribute(0, -1);
    cout << order.size() << '\n';
    for(long long i = 0; i < order.size(); i++){
        cout << get<0>(order[i])+1 << ' ' << get<1>(order[i])+1 << ' ' << get<2>(order[i]) << '\n';
    }
} 