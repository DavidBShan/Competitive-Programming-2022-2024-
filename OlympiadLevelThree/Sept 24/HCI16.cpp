#include <bits/stdc++.h>
using namespace std;
int main()
{
    int xT, yT, x, y;
    int possible[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char inp;
    pair<int, int> start;
    pair<int, int> endC;
    set<pair<int, int>> bad;
    map<pair<int, int>, int> dist;
    queue<pair<int, int>> q;
    cin >> xT >> yT;
    for (int i = 0; i < xT; i++)
    {
        for (int j = 0; j < yT; j++)
        {
            cin >> inp;
            if (inp == 's')
            {
                start = {i, j};
                dist[start] = 0;
                q.push(start);
            }
            else if (inp == 'e')
            {
                endC = {i, j};
            }
            else if (inp == 'X')
            {
                bad.insert({i, j});
            }
        }
    }

    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + possible[k][0], ny = y + possible[k][1];
            if (nx < 0 || nx >= xT || ny < 0 || ny >= yT || dist.find({nx, ny}) != dist.end() || bad.find({nx, ny}) != bad.end())
                continue;
            q.push({nx, ny});
            dist[{nx, ny}] = dist[{x, y}] + 1;
            if (endC.first == nx && endC.second == ny)
            {
                cout << dist[{x, y}];
                exit(0);
            }
        }
    }
    cout << -1;
}