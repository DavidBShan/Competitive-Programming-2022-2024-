#include <bits/stdc++.h>
using namespace std;

int maxCaptured = 0;
vector<pair<int, int>> aLoc(0);
char board[9][9];
pair<int, int> dir[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void dfs(int curX, int curY, int parX, int parY, char checkBoard[9][9], int maxC) {
    for (int i = 0; i < 4; i++) {
        char newBoard[9][9];
        memcpy(newBoard, checkBoard, sizeof(newBoard));
        int newX = curX + dir[i].first, newY = curY + dir[i].second;
        if (newX < 1 || newX > 8 || newY < 1 || newY > 8) continue;
        if (newX == parX && newY == parY) continue;
        if (newBoard[newX][newY] == 'B') {
            if (newBoard[newX + dir[i].first][newY + dir[i].second] == '.') {
                newBoard[newX][newY] = '.';
                maxCaptured = max(maxCaptured, maxC+1);
                dfs(newX + dir[i].first, newY + dir[i].second, newX, newY, newBoard, maxC+1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    aLoc.clear();

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            char a;
            cin >> a;
            board[i][j] = a;
            if (a == 'A') {
                aLoc.push_back({i, j});
            }
        }
    }

    for (int a = 0; a < aLoc.size(); a++) {
        char checkBoard[9][9];
        memcpy(checkBoard, board, sizeof(board));
        dfs(aLoc[a].first, aLoc[a].second, 0, 0, checkBoard, 0);
    }

    cout << maxCaptured;
}
