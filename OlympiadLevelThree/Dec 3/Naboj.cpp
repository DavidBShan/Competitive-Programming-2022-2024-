#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, m; int inDeg[MM];vector<int> graph[MM];
int main(){
    cin >> n >> m;
    for(int i = 1,a,b; i <= m;i++){
        cin >> a >> b;
        inDeg[a]++; graph[b].push_back(a);
    }
    queue<int> q; vector<int> ans;
    for(int i = 1; i <= n;i++){
        if(inDeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int a = q.front(); q.pop(); ans.push_back(a);
        for(int b: graph[a]){
            if(--inDeg[b]==0){
                q.push(b);
            }
        }
    }
    if(ans.size()!=n) cout << "-1"<<"\n";
    else{
        cout << ans.size()<<endl;
        for(int i = 0; i < ans.size();i++){
            cout << ans[i]<<" 1\n";
        }
    }
}