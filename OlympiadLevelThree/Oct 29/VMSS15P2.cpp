#include <bits/stdc++.h>
using namespace std;
int r,c,countN = 0; bool visited[100][100]; char temp;
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void bfs(int sX, int sY){
    int tx,ty,qx,qy;
    queue<pair<int,int>> q;
    visited[sX][sY] = true; q.push({sX,sY});
    while(!q.empty()){
        tx = q.front().first; ty = q.front().second;
        q.pop();
        for(int i = 0; i < 4;i++){
            qx = tx+direction[i][0]; qy = ty+direction[i][1];
            if((qx>=0&&qx<r)&&(qy>=0&&qy<c)&&visited[qx][qy]==false){
                q.push({qx,qy}); visited[qx][qy] = true;
            }
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r;i++){
        for(int j = 0; j < c;j++){
            cin >> temp;
            if(temp == 'X') visited[i][j] = true;
        }
    }for(int z = 0; z < r;z++){
        for(int j = 0; j<c;j++){
            if(visited[z][j]==false){
                bfs(z,j);
                countN++;
            }
        }
    }
    cout << countN;
}