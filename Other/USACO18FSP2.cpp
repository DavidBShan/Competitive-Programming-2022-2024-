#include <bits/stdc++.h>
using namespace std;
const int MM = 252;
int N, B; pair<int, int> boots[MM]; int depth[MM];
bool visited[MM][MM]; int ans = 1e9;
void dfs(int cur, int boot){
    if(visited[cur][boot]) return;
    visited[cur][boot] = true;
    if(cur == N-1){
        ans = min(ans, boot); return;
    }
    for(int i = cur+1; i < N && i-cur <= boots[boot].second; i++){
        if(depth[i] <= boots[boot].first) dfs(i, boot);
    }
    for(int i = boot+1; i < B; i++){
        if(depth[cur] <= boots[i].first) dfs(cur, i);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> B;
    for(int i = 0; i < N; i++) cin >> depth[i];
    for(int i = 0, temp1, temp2; i < B; i++){
        cin >> temp1 >> temp2; boots[i] = {temp1, temp2};
    }
    dfs(0, 0);
    cout << ans;
}