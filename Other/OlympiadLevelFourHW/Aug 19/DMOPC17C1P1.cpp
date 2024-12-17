#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int R, C; cin >> R >> C; set<int> rowSet; set<int> colSet;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <=C; j++){
            char temp; cin >> temp;
            if(temp=='X'){rowSet.insert(i); colSet.insert(j);}
        }
    }
    int Q; cin >> Q;
    for(int i = 0, x, y; i < Q; i++){
        cin >> x >> y;
        if(colSet.find(x)!=colSet.end() || rowSet.find(y)!=rowSet.end()){cout << "Y\n";}
        else cout << "N\n";
    }
}