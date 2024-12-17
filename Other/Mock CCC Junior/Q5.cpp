#include <bits/stdc++.h>
using namespace std;
int N, K;
const int MM = 805;
char grid[MM][MM]; set<pair<int, int>> wall; int minAns = INT_MAX;
pair<int, int> enter; pair<int, int> ext;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[MM][MM];

void rotate() {
    char newGrid[MM][MM];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            newGrid[j][N - i - 1] = grid[i][j];
        }
    }
    memcpy(grid, newGrid, sizeof(grid));
}

void dfs(int enterX, int enterY, int turnC){
    int newX = enterX, newY = enterY;
    if((turnC+1) % K == 0){
        newX = enterY;
        newY = N - enterX - 1;
        if(grid[newX][newY] == 'W'){
            return;
        }
    }
    if(newX == ext.first && newY == ext.second){
        minAns = min(minAns, turnC);
        return;
    }
    visited[newX][newY] = true;
    for(int i = 0; i < 4; i++){
        int nextX = newX + dir[i][0]; int nextY = newY + dir[i][1];
        if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || grid[nextX][nextY] == 'W' || visited[nextX][nextY]){
            continue;
        }
        dfs(nextX, nextY, turnC+1);
    }
    visited[newX][newY] = false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'W'){
                wall.insert({i, j});
            }else if(grid[i][j] == 'E'){
                enter = {i, j};
            }else if(grid[i][j] == 'X'){
                ext = {i, j};
            }
        }
    }
    dfs(enter.first, enter.second, 0);
    if(minAns == INT_MAX) {
        cout << -1;
    } else {
        cout << minAns;
    }
}