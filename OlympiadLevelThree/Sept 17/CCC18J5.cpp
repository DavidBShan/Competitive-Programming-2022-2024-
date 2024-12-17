#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> book;
void BFS(int v, int pages)
{
    queue<int> q;
    vector<bool> visited;
    visited.resize(pages + 1, false);
    vector<int> distance;
    distance.resize(pages + 1, 0);
    int min = 2000000000;
    bool vF = true;
    visited[v] = true;
    q.push(v);
    visited[0] = true;
    distance[v] = 1;
    bool vE = false;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (book.find(v) == book.end()&&vE==false)
        {
            min = distance[v];
            vE = true;
        }
        for (int i = 0; i < book[v].size(); i++)
        {
            if (!visited[book[v][i]])
            {
                visited[book[v][i]] = true;
                distance[book[v][i]] = distance[v] + 1;
                q.push(book[v][i]);
            }
        }
    }
    for (int i = 0; i <= pages; i++)
    {
        if (visited[i] == false)
        {
            vF = false;
        }
    }
    if (vF == true)
        cout << "Y" << endl
             << min << endl;
    else
        cout << "N" << endl
             << min << endl;
}

int main()
{
    int pages;
    cin >> pages;
    int val;
    int page;

    for (int i = 1; i <= pages; i++)
    {
        cin >> val;
        for (int j = 0; j < val; j++)
        {
            cin >> page;
            book[i].push_back(page);
        }
    }
    BFS(1, pages);
}