#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, x, y, w, h, count = 0;
    cin >> N >> M;
    int dif[10003][10003];

    for(int i = 0; i < M; i++){
        cin >> x >> y >> w >> h;
        dif[x][y]++; dif[x+w][y]--; dif[x][y+h]--; dif[x+w][y+h]--;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i==0 && j==0){}
            if(i==0){
                dif[i][j] += dif[i][j-1];
            }else if(j==0){
                dif[i][j] += dif[i-1][j];
            }else{
                dif[i][j] += dif[i][j-1]+dif[i-1][j]-dif[i-1][j-1];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dif[i][j]%2!=0){
                count++;
            }
        }
    }
    cout << count;
}