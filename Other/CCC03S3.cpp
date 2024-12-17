#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
struct edge { int u, v, w;};
bool cmp(edge x, edge y){ return x.w > y.w; }
int N, M, D; vector<edge> edges; int p[MM]; vector<int> dest;
int Find(int d){ return d==p[d]? d : p[d] = Find(p[d]); }
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> D;
    for(int i = 1; i <= N; i++) p[i] = i;
    for(int i = 0, a, b, c; i < M; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    for(int i = 0; i < D; i++){
        int a; cin >> a; dest.push_back(a);
    }
    int ans = 0;
    for(int i = 0, j = 0; i < D; i++){
        for(; Find(dest[i]) != Find(1); j++){
            int a, b, c; 
            a = edges[j].u; b = edges[j].v; c = edges[j].w;
            if(Find(a) != Find(b)){
                p[Find(a)] = Find(b);
                ans = min(ans, c);
            }
        }
    }
    cout << ans;
}