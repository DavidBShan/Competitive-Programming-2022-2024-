#include <bits/stdc++.h>
using namespace std;

int main()
{
    int visited[35][50];
    char graph[35][50];
    queue<pair<int, int>> q;
    int R, C;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int group = 0;
    int x, y, nx, ny;
    vector<pair<int, int>> monkey;
    set<int> groupM;
    int curGroup;
    int count = 0;
    cin >> R >> C;
    memset(visited, -1, sizeof visited);
    memset(graph, '0', sizeof graph);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == '#')
                visited[i][j] = group;
            if (graph[i][j] == 'M')
                monkey.push_back({i, j});
        }
    }
    group++;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if ((graph[i][j] == '.' || graph[i][j] == 'M') && (visited[i][j] == -1))
            {
                q.push({i, j});
                visited[i][j] = group;
                while (!q.empty())
                {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for (int a = 0; a < 4; a++)
                    {
                        nx = x + dir[a][0];
                        ny = y + dir[a][1];
                        if ((nx < R && nx >= 0 && ny < C && ny >= 0) && (visited[nx][ny] == -1))
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = group;
                        }
                    }
                }
                group++;
            }
        }
    }
    for (int i = 0; i < monkey.size(); i++)
    {
        curGroup = visited[monkey[i].first][monkey[i].second];
        if (groupM.find(curGroup) == groupM.end())
        {
            groupM.insert(curGroup);
            count++;
        }
    }
    cout << count;
}