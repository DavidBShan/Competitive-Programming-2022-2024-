    #include <bits/stdc++.h>
    using namespace std;
    const int MM = 205;
    int X, Y, x, y, d[MM][MM], ans; char g[MM][MM];
    int main(){
        cin >> X >> Y >> x >> y; y = Y-y+1;
        for(int i = 1; i <=Y;i++){
            for(int j = 1;j<=X;j++){
                cin >> g[i][j];
            }
        }
        queue<pair<int,int>> q; memset(d,-1,sizeof d);
        q.push({y,x}) ; d[y][x] = 0;
        while(!q.empty()){
            auto [y,x] = q.front(); q.pop();
            ans = d[y][x]; 
            for(int dy = -1; dy<=1;dy++){
                for(int dx = -1; dx<=1;dx++){
                    int ny=y+dy, nx = x+dx;
                    if(1<=ny&&ny<=Y&&1<=nx&&nx<=X&&d[ny][nx]==-1&&g[ny][nx]!='*'){
                        q.push({ny,nx});d[ny][nx] = d[y][x]+1;
                    }
                }
            }
        }
        cout << ans<<endl;
    }