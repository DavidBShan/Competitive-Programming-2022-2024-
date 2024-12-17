#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int F[MM][MM], newF[MM][MM], N;

bool check(){
    for(int i = 0; i < N; i++){
        for (int j = 1; j < N; j++){
            if(newF[i][j] < newF[i][j-1]){
                return false;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(newF[j][i] < newF[j-1][i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> F[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            newF[i][j] = F[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        if(check()==true){
            for(int a = 0; a < N; a++){
                for (int b = 0; b < N; b++){
                    cout << newF[a][b] << " ";
                }
                cout << "\n";
            }
            return 0;
        }else{
            for(int a = 0; a < N; a++){
                for(int b = 0; b < N; b++){
                    F[a][b] = newF[a][b];
                }
            }
        }
        for(int a = 0; a < N; a++){
            for (int b = 0; b < N; b++){
                newF[a][b] = F[b][N-1-a];
            }
        }
    }
}