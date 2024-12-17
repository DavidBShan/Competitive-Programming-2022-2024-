#include <iostream>
#define NODE 4
using namespace std;

int graph[NODE][NODE];

bool isCycle(int u, bool visited[], int parent)
{
    visited[u] = true; // mark v as visited
    for (int v = 0; v < NODE; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
            { // when the adjacent node v is not visited
                if (isCycle(v, visited, u))
                {
                    return true;
                }
            }
            else if (v != parent)
            {                // when adjacent vertex is visited but not parent
                return true; // there is a cycle
            }
        }
    }
    return false;
}

bool isTree()
{
    bool *vis = new bool[NODE];

    for (int i = 0; i < NODE; i++)
        vis[i] = false; // initialize as no node is visited

    if (isCycle(0, vis, -1)) // check if there is a cycle or not
        return false;

    for (int i = 0; i < NODE; i++)
    {
        if (!vis[i]) // if there is a node, not visited by traversal, graph is not connected
            return false;
    }
    return true;
}

int main()
{
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4;j++){
            cin >> graph[i][j];
        }
    }
    if (isTree())
        cout << "Yes";
    else
        cout << "No";
}