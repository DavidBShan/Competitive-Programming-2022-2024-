#include <bits/stdc++.h>

using namespace std;

char a[105][105];
int dis[105][105];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int posX;
int posY;
queue<pair<int, int>> q;
void push(int ny, int nx, int nd){
    if(a[ny][nx] != 'W' && a[ny][nx] != 'C' && dis[ny][nx] != -1 && nd < dis[ny][nx]){
        dis[ny][nx] = nd;  q.push({ny, nx});
    }
}
void bfs(){
    if(dis[posY][posX] != -1) q.push({posY, posX});
    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        if (a[u.first][u.second] == 'U') push(u.first-1, u.second, dis[u.first][u.second]);
        else if (a[u.first][u.second] == 'D') push(u.first+1, u.second, dis[u.first][u.second]);
        else if (a[u.first][u.second] == 'L') push(u.first, u.second-1, dis[u.first][u.second]);
        else if (a[u.first][u.second] == 'R') push(u.first, u.second+1, dis[u.first][u.second]);
        else {
            for (int i = 0; i < 4; i++) {
                int ny = u.first + dir[i][0];
                int nx = u.second + dir[i][1];
                push(ny, nx, dis[u.first][u.second] + 1);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            a[i][j] = 'W';
            dis[i][j] = 1000000;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                posX = j;
                posY = i;
                dis[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'C') {
                dis[i][j] = -1;
                for (int k = 0; k < 4; k++) {
                    int ny = i;
                    int nx = j;
                    while (a[ny][nx] != 'W') {
                        ny += dir[k][0];
                        nx += dir[k][1];
                        if (a[ny][nx] == '.' || a[ny][nx] == 'S') {
                            dis[ny][nx] = -1;
                        }
                    }
                }
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') {
                if (dis[i][j] == 1000000) {
                    cout << -1 << endl;
                }
                else {
                    cout << dis[i][j] << endl;
                }
            }
        }
    }

}