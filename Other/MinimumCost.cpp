#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef array<int, 4> E;
int N, M, D, p[MM], ans, last, lastw; vector<E> edge;
int fd(int d){ return d==p[d]? d : p[d]=fd(p[d]);}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> D;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1, u, v, w; i<=M; i++) {
        cin >>u >> v >> w;
        edge.push_back({w, i>=N, u, v});
    }
    sort(edge.begin(), edge.end());
    for(int i=0; i<edge.size(); i++){
        auto [w, t, u, v] = edge[i];
        int fu = fd(u), fv = fd(v);
        if(fu!=fv){
            p[fu] = fv; ans+=t;last = i; lastw = w;
        }
    }
    if(edge[last][1] && lastw <= D){
        for(int i=0; i<N; i++) p[i] = i;
        for(int i=0; i<last; i++){
            auto [w, t, u, v] = edge[i];
            if(t == 0 || w < lastw) p[fd(u)] = fd(v);
        }
        for(int i=last+1; i<edge.size(); i++){
            auto [w, t, u, v] = edge[i];
            if(t==0 && w <= D && fd(u) != fd(v)) { ans--; break; }
        }
    }
    cout << ans << endl;
}