#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_map<string, int> mp;
    int X, Y, G; cin >> X; string x[X+2][2];
    for(int i = 0; i < X; i++){
        cin >> x[i][0] >> x[i][1];
    }
    cin >> Y; string y[Y+2][2];
    for(int i = 0; i < Y; i++){
        cin >> y[i][0] >> y[i][1];
    }
    cin >> G;
    for(int i = 0; i < G; i++){
        string temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        mp[temp1] = i; mp[temp2] = i; mp[temp3] = i;
    }
    int ans = 0;
    for(int i = 0; i < X; i++){
        if(mp[x[i][0]] != mp[x[i][1]]) ans++;
    }
    for(int i = 0; i < Y; i++){
        if(mp[y[i][0]] == mp[y[i][1]]) ans++;
    }
    cout << ans;
}