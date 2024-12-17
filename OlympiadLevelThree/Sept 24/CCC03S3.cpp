#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<pair<int, int>> visited;
    int TotalSur, x, y;
    char inp;
    int moveOp[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    vector<int> counter;
    int xT, yT;
    int countR = 0, countT = 0;
    cin >> TotalSur >> x >> y;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> inp;
            if (inp == 'I')
            {
                visited.insert({i, j});
            }
        }
    }
    while (visited.size() < (x * y))
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (visited.find({i, j}) == visited.end())
                {
                    q.push({i, j});
                    visited.insert({i, j});
                    countT++;
                    while (!q.empty())
                    {
                        int xT = q.front().first, yT = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = xT + moveOp[k][0], ny = yT + moveOp[k][1];
                            if (nx < 0 || nx >= x || ny < 0 || ny >= y || visited.find({nx, ny}) != visited.end())
                                continue;
                            q.push({nx, ny});
                            visited.insert({nx, ny});
                            countT++;
                        }
                    }
                    counter.push_back(countT);
                    countT = 0;
                }
            }
        }
    }
    sort(counter.begin(), counter.end(), greater<int>());
    while (countR < counter.size())
    {
        if (counter[countR] <= TotalSur)
        {
            TotalSur -= counter[countR];
            countR++;
        }
        else
        {
            break;
        }
    }
    if (countR == 1)
    {
        cout << countR << " room, " << TotalSur << " square metre(s) left over";
    }
    else
    {
        cout << countR << " rooms, " << TotalSur << " square metre(s) left over";
    }
}
