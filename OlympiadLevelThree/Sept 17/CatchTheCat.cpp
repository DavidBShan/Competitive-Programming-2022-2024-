#include<bits/stdc++.h>
using namespace std;
int Roger, Cat;
vector<bool> visited; 
vector<int> dist;

void BFS(int Roger, int Cat){
    queue<int> q;
    visited.resize(100001, false);
    dist.resize(100001, 0);
    visited[Roger] = true;
    q.push(Roger);
    while (!q.empty())
    {
        Roger = q.front();
        q.pop();
        if(Roger*2<=100001){
            if(!visited[Roger*2]){
                visited[Roger * 2] = true;
                dist[Roger * 2] = dist[Roger] + 1;
                q.push(Roger*2);
            }
        }
        if(Roger+1<=100001){
            if (!visited[Roger+1]){
                visited[Roger + 1] = true;
                dist[Roger + 1] = dist[Roger] + 1;
                q.push(Roger+1);
            }
        }
        if (Roger - 1 >=0)
        {
            if (!visited[Roger - 1])
            {
                visited[Roger -1] = true;
                dist[Roger - 1] = dist[Roger] + 1;
                q.push(Roger - 1);
            }
        }
        if(visited[Cat]==true){
            cout << dist[Cat];
            break;
        }
    }
}

int main(){
    cin >> Roger >> Cat;
    BFS(Roger, Cat);
}