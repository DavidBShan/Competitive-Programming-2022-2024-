#include <bits/stdc++.h>
using namespace std;
int n, st, ed; bitset<1<<21>vis;

int bfs(int start, int end){
    queue<int>q; q.push(start);
    vis[start] = 1; int step = 0; 
    while(!q.empty()){
        for(int i = q.size(); i>0; i--){
            int cur = q.front(); q.pop();
            if(cur == end) return step;
            vector<int>arr(7, -1);
            for(int j = n-1; j >= 0; j--){
                arr[(cur >> j*3) & 7] = j;
            }
            for(int j = 0; j < n; j++){
                if(arr[j] == -1) continue;
                if(j!=n-1 && (arr[j+1]==-1 || arr[j] < arr[j+1])){
                    int next = (cur ^ (j<<arr[j]*3))|(j+1 << arr[j]*3);
                    if(!vis[next]){
                        vis[next] = 1;
                        q.push(next);
                    }
                }
                if(j!=0 && (arr[j-1]==-1 || arr[j] < arr[j-1])){
                    int next = (cur ^ (j << arr[j]*3)) | (j-1 << arr[j]*3);
                    if(!vis[next]){
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        step++;
    }
    return -1;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> n; if(n==0) break;
        vis.reset(); st = 0; ed = 0;
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            st |= i << (temp-1)*3;
            ed |= i << i*3;
        }
        int ans = bfs(st, ed);
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}