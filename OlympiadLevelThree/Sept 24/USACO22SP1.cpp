#include <bits/stdc++.h>
using namespace std;

int BFS(int beg, int end)
{
    queue<int> q;
    set<int> visited;
    int count = 0;
    unordered_map<int, int> distance;
    int temp;
    q.push(beg);
    distance[beg] = 0;
    visited.insert(beg);
    if(end == beg){
        return 0;
    }
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == end)
        {
            cout << distance[temp]<<endl;
            break;
        }
        if(temp>end && temp%2==0){
            q.push(temp/2);
            distance[temp/2] = distance[temp]+1;
        }else if(temp > end && temp%2==1){
            q.push(temp+1);
            distance[temp+1] = distance[temp]+1;
        }else{
            q.push(temp*2);
            q.push(temp+1);
            distance[temp+1] = distance[temp]+1;
            distance[temp*2] = distance[temp] + 1;
        }if(temp <2)
    }
}

int main()
{
    int times;
    int beg, end;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        cin >> beg >> end;
        cout << BFS(beg, end) << endl;
    }
}