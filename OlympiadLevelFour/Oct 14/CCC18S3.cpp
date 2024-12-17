#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int N, M; int dis[MM][MM]; char grid[MM][MM]; bool vis[MM][MM];
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
queue<pair<int, int>> q; set<pair<int, int>> cam;
int startX, startY;

void push(int ny, int nx, int nd){
    if(grid[ny][nx] != 'W' && grid[ny][nx] != 'C' && vis[ny][nx] != true && nd < dis[ny][nx]){
        dis[ny][nx] = nd;  q.push({ny, nx});
    }
}

void bfs(){
    q.push({startX, startY});
    while(!q.empty()){
        int curX = q.front().first, curY = q.front().second; q.pop();
        if(grid[curX][curY]=='L')push(curX-1, curY, dis[curX][curY]);
        else if(grid[curX][curY]=='R'){
            int newX = curX+1; int newY = curY;
            if(newX >= 0 && newX < N && newY >= 0 && newY < M && !vis[newX][newY]){
                dis[newX][newY] = dis[curX][curY]+1;
                q.push({newX, newY});
            }
        }
        else if(grid[curX][curY]=='U'){
            int newX = curX; int newY = curY-1;
            if(newX >= 0 && newX < N && newY >= 0 && newY < M && !vis[newX][newY]){
                dis[newX][newY] = dis[curX][curY]+1;
                q.push({newX, newY});
            }
        }
        else if(grid[curX][curY]=='D'){
            int newX = curX; int newY = curY+1;
            if(newX >= 0 && newX < N && newY >= 0 && newY < M && !vis[newX][newY]){
                dis[newX][newY] = dis[curX][curY]+1;
                q.push({newX, newY});
            }
        }else{
            for(int i = 0; i < 4; i++){
                int newX = curX+dir[i][0], newY = curY+dir[i][1];
                if(newX >= 0 && newX < N && newY >= 0 && newY < M && !vis[newX][newY] && cam.find({newX, newY})==cam.end()){
                    dis[newX][newY] = dis[curX][curY]+1;
                    q.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    memset(dis, -1, sizeof(dis));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'W') {vis[i][j] = true;dis[i][j] = -1;}
            if(grid[i][j] == 'S'){startX = i; startY = j; dis[i][j] = 0;}
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 'C'){ 
                for(int i = 0; i < 4; i++){
                    int newX = i, newY = j;
                    while(newX >= 0 && newX < N && newY >= 0 && newY < M && grid[newX][newY] != 'W'){
                        cam.insert({newX, newY});
                        dis[newX][newY] = -1;
                        newX += dir[i][0]; newY += dir[i][1];
                    }
                }
            }
            
        }
    }
    bfs();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j]=='.'){
                cout << dis[i][j] << "\n";
            }
        }
    }
}