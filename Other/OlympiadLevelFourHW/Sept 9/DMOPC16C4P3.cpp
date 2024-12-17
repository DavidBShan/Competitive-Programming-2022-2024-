#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3, appleMax = 101;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); set<pair<int, int>> stands[appleMax];
    int N, S; cin >> N >> S; int dist[MM];
    for(int i = 1; i <= N; i++) cin >> dist[i];
    for(int i = 1, a, b; i <= S; i++){
        cin >> a >> b;  stands[b].insert({dist[a], a});
    }
    int Q; cin >> Q; char op;
    for(int i = 1, x, k; i <= Q; i++){
        cin >> op;
        if(op=='A'){
            cin >> x >> k; stands[k].insert({dist[x], x});
        }else if(op=='S'){
            cin >> x >> k; stands[k].erase({dist[x],x});
        }else if(op=='E'){
            cin >> x >> k;
            for(int i=1; i<appleMax; i++) stands[i].erase({dist[x], x});
            dist[x] = k;
        }else{
            cin >> k;
            if(stands[k].empty()) cout << "-1\n";
            else cout << (*(stands[k].begin())).second << "\n";
        }
    }
}