#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M; int p[MM];
int fd(int x){
    if(p[x] == x) return x;
    return p[x] = fd(p[x]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M; vector<int> ans;
    for(int i = 1; i <= N; i++) p[i] = i;
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        if(fd(a) != fd(b)) {p[fd(a)] = fd(b); ans.push_back(i+1);}
        if(ans.size() == N-1) break;
    }
    if(ans.size() == N-1) for(int i : ans) cout << i << "\n";
    else cout << "Disconnected Graph";
}