#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int N, K, F;
bool gyms[MM];
vector<int> adj[MM];
int diameter = 0;
int depth[MM], dist[MM];
void dfs(int cur, int par)
{
    dist[cur] = 0;
    for (int i : adj[cur])
    {
        if (i == par)
            continue;
        depth[i] = depth[cur] + 1;
        dfs(i, cur);
        if (gyms[i])
        {
            dist[cur] += dist[i] + 1;
            gyms[cur] = true;
        }
    }
    if (gyms[cur])
    {
        diameter = max(diameter, depth[cur]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> F;
    for (int i = 1; i <= K; i++)
    {
        int temp;
        cin >> temp;
        gyms[temp] = true;
    }
    for (int i = 1, a, b; i < N; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // depth[1] = 0;
    dfs(1, -1);
    int ans1 = 2 * dist[1] - diameter;
    gyms[F] = true;
    dfs(1, -1);
    int ans2 = dist[1];
    cout << min(ans1, ans2) << endl;
}
