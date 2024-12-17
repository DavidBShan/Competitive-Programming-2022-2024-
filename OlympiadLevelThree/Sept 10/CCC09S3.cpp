#include <bits/stdc++.h>
using namespace std;

bool matrix[50][50] = {false};
queue<int> q;
bool visited[50] = {false};
int dist[50] = {0};

int countF(int num){
    int count = 0;
    for(int i = 0; i < 50;i++){
        if(matrix[num][i]==true){
            count++;
        }
    }
    return count;
}

void bfs(int x)
{
    q.push(x);
    visited[x] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < 50;i++){
            if(matrix[v][i]==1){
                if (!visited[i])
                {
                    dist[i] = dist[v] + 1;
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

int countFF(int num){
    int count = 0;
    for(int j = 0; j < 50;j++){
        if(matrix[num][j]==true){
            for(int i = 0; i < 50;i++){
                if(i!=num){
                    if(matrix[j][i]==true){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    string ins; int totalC = 0; int temp1, temp2;
    cin >> ins;
    matrix[6][7]=true; matrix[7][6] = true; matrix[2][6] = true; matrix [6][2] = true;matrix[1][6] = true;matrix[6][1] = true; matrix[3][6] = true; matrix[6][3] = true; matrix [4][6] = true; matrix [5][6] = true; matrix [6][4] = true; matrix [6][5] = true; matrix [6][7] = true; matrix [7][6] = true; matrix [3][5] = true; matrix [5][3] = true; matrix [7][8] = true; matrix [8][7] = true; matrix [3][15] = true; matrix [15][3] = true; matrix [15][13] = true; matrix [13][15] = true; matrix [12][13] = true; matrix [13][12] = true; matrix [11][12] = true; matrix [12][11] = true; matrix[14][13]=true;matrix[13][14] = true; matrix[12][9] = true; matrix[9][12] = true; matrix[10][9] = true; matrix[10][9] = true;matrix[8][9] = true; matrix[9][8] = true;
    while (ins != "q")
    {
        if (ins == "i")
        {
            cin >> temp1 >> temp2;
            matrix[temp1][temp2] = true;
            matrix[temp2][temp1] = true;
        }else if(ins == "d"){
            cin >> temp1 >> temp2;
            matrix[temp1][temp2] = false;
            matrix[temp2][temp1] = false;
        }else if(ins == "n"){
            cin >> temp1;
            cout << countF(temp1) << endl;
        }else if(ins == "f"){
            cin >> temp1;
            cout << countFF(temp1) << endl;
        }else if(ins == "s"){
            memset(visited, false, sizeof(visited));
            memset(visited, 0, sizeof(dist));
            cin >> temp1>>temp2;
            bfs(temp1);
            cout << ((visited[temp2]) ? to_string(dist[temp2]) : "Not connected") << "\n";
        }
        cin >> ins;
    }
}