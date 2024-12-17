	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
struct E {
  int u, v, w, f;
};
int N, M, D, p[MM], ans, last; vector<E> edge;
int fd(int d) {  return d==p[d]? d : p[d] = fd(p[d]); }
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> D;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1, u, v, w; i<=M; i++){
        cin >> u >> v >> w;
        edge.push_back(E{u, v, w, i>N-1});
    }
    sort(edge.begin(), edge.end(), [](E& x, E& y) { return x.w < y.w || (x.w==y.w && x.f < y.f); });
    for(int i=0; i<edge.size(); i++){
        int u = fd(edge[i].u), v = fd(edge[i].v);
        if(u != v) {
            p[u] = v;  ans += edge[i].f;  last = i;
        }
    }
    if(edge[last].f) { //last edge must be a new edge
        int cost = edge[last].w;
        for(int i=1; i<=N; i++) p[i] = i;
        for(int i=0; i<last; i++) {
            if(edge[i].f == 0 || edge[i].w < cost){
                int u = fd(edge[i].u), v = fd(edge[i].v);
                if(u != v) p[u] = v;
            }
        }
        for(int i=last; i<edge.size(); i++) {
            if(edge[i].f == 0 && edge[i].w <= D) {
                int u = fd(edge[i].u), v = fd(edge[i].v);
                if(u != v) { ans--; break;}
            }
        }
    }
    cout << ans << endl;
}   