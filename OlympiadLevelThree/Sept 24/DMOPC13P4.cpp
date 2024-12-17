#include <bits/stdc++.h>
using namespace std;
int main()
{
    int xT, yT, x, y, times;
    int possible[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char inp;
    pair<int, int> start;
    pair<int, int> endC;
    int visited[55][55];
    bool over60 = false;
    queue<pair<int, int>> q;
    cin >> times;
    for (int z = 0; z < times; z++)
    {
        memset(visited, -2, sizeof visited);
        cin >> xT >> yT;
        for (int i = 0; i < xT; i++)
        {
            for (int j = 0; j < yT; j++)
            {
                cin >> inp;
                if (inp == 'C')
                {
                    start = {i, j};
                    visited[i][j] = 0;
                    q.push(start);
                }
                else if (inp == 'W')
                {
                    endC = {i, j};
                }
                else if (inp == 'X')
                {
                    visited[i][j] = 1000;
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
                if (nx < 0 || nx >= xT || ny < 0 || ny >= yT || visited[nx][ny] >= 0)
                {
                    continue;
                }
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                if (endC.first == nx && endC.second == ny)
                {
                    cout << visited[nx][ny] + 1 << endl;
                    continue;
                }
                if (visited[nx][ny] >= 59)
                {
                    over60 = true;
                    break;
                }
            }
            if (over60 == true)
            {
                cout << "not worth good";
                over60 = false;
                break;
            }
        }
        memset(visited, -2, sizeof visited);
        q = queue<pair<int, int>>();
    }
}