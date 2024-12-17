#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y, N; cin >> X >> Y >> N; bool visited[X+1][Y+1]; int count = 0;
    memset(visited,false,sizeof visited); 
    for(int i = 0,x1,y1,x2,y2; i < N;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j <=x2;j++){
            for(int z = y1; z<=y2;z++){
                if(visited[j][z]==false){
                    count++; visited[j][z]=true;
                }
            }
        }
    }
    cout << count;
}