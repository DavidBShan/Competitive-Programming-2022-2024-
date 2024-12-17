#include <bits/stdc++.h>
using namespace std;
int T, N, Q, C;

void solve(){
    cin >> N >> Q >> C;
    vector<int> cow(N+1, 0), f(N+1, 0), dif(N+2, 0); vector<pair<int, int>> cons;
    for(int i = 1; i <= N; i++) cin >> cow[i];
    for(int i = 1, a, h; i<=Q;i++){
        cin >> a >> h;
        if(a > h) {cout << -1<<endl; return;}
        cons.push_back({a,h});
        if(a+1 <= h-1) {dif[a+1]++; dif[h]--;}
        f[h]=1;
    }
    for(int i = 1; i <= N; i++){
        dif[i]+=dif[i-1];
        if(dif[i] > 0){
            if(f[i] > 0){
                cout << -1<<endl; return;
            }
            f[i] = -1;
        }
    }
    int mx = 0, last = 0;
    for(int i = 1; i<= N; i++){
        if(f[i] == -1){
            if(cow[i] == 0) cow[i] = 1;
            else if(cow[i]>mx){
                if(!last) {cout << -1 <<endl; return;}
                cow[last] = cow[i];
            }
        }else if(f[i] == 1){
            if(cow[i] == 0) {
                cow[i] = mx+1; last = i;
            } else if(cow[i] <= mx) {cout << -1<<endl; return;}
        }else{
            if(cow[i] == 0){
                cow[i] = 1; last = i;
            }
        }
        mx =  max(mx, cow[i]);
    }
    mx = 0;
    for(int i = 1; i <= N; i++){
        if((f[i] == -1 && cow[i]>mx) || (f[i] == 1 && cow[i] <= mx) || (cow[i] > C)){
            cout << -1<<endl; return;
        }
        mx = max(mx, cow[i]);
    }
    for(int i = 1; i <= N; i++){
        cout << cow[i] << (i != N ? " " : "\n");
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(cin>>T; T--;) solve();
}