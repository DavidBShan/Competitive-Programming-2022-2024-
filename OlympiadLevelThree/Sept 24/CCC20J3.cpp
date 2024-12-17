#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
map<pair<int, int>, vector<pair<int, int>>> room;
int row, col, temp;
vector<vector<bool>> visited;

void BFS(pair<int, int> f)
{
    visited.resize(row + 1, vector<bool>(col + 1));
    for (auto &i : visited)
        fill(i.begin(), i.end(), false);
    q.push(f);
    int sx = f.first;
    int sy = f.second;
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cout << room[{x, y}].size();
        for (int i = 0; i < room[{x, y}].size(); i++)
        {
            sx = room[{x, y}][0].first;
            sy = room[{x, y}][0].second;
            cout << sx << sy;
            if (!visited[sx][sy])
            {
                visited[sx][sy] = true;
                q.push({sx, sy});
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    map<pair<int, int>, vector<pair<int, int>>> test = room;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> temp;
            for (int a = 1; a <= min(temp, col); a++)
            {
                if (temp % a == 0)
                {
                    room[{row, col}].push_back({a, temp / a});
                }
            }
            for (int z = 0; z < room[{row, col}].size(); z++)
            {
                cout << row << " " << col << room[{row, col}][z].first << " " << room[{row, col}][z].second << endl;
            }
        }
    }
    BFS({1, 1});
    if (visited[row][col] == true)
        cout << "yes";
    else
        cout << "no";
}