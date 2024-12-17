#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int mov[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int cells[1001][1001], cow[1001][1001], ans = 0;
    for(int i = 0,x,y; i < N;i++){
        cin >> x >> y; cow[x][y] = true;
        if(cells[x][y]==3) ans ++;
        for(int j = 0; j < 4;j++){
            if((x+mov[j][0])>=0&&(y+mov[j][1])>=0&&(y+mov[j][1])<1000&&(x+mov[j][0])<1000){
                cells[x+mov[j][0]][y+mov[j][1]]++;
                if(cells[x+mov[j][0]][y+mov[j][1]]==3&&cow[x+mov[j][0]][y+mov[j][1]]==true) ans++;
                else if(cells[x+mov[j][0]][y+mov[j][1]]==4&&cow[x+mov[j][0]][y+mov[j][1]]==true) ans--;
            }
        }
        cout << ans<<endl;
    }
}   