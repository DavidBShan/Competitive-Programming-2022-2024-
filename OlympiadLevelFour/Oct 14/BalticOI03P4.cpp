#include <bits/stdc++.h>
using namespace std;
const int MM = 1003;
set<int> vis; int N, M, p[2*MM];
int fd(int d) {return d==p[d] ? d: fd(p[d]);}
void join (int u, int v){
    p[fd(u)] = fd(v);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < 2*MM; i++) p[i] = i;
    for(int i = 0; i < M; i++){
        char op; int u, v; cin >> op >> u >> v;
        if(op == 'F') join(u, v);
        else join(u, v+MM), join(u+MM, v);
    }
    for(int i = 1; i <= N; i++) vis.insert(fd(i));
    cout << vis.size() << endl;
}