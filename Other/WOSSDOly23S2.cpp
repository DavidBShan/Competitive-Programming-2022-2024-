#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K; int curTime = 0; vector<pair<int, int>> cur; cur.push_back({0, 0});
    for(int i = 0, a, b, t; i < M; i++){
        cin >> a >> b >> t; vector<pair<int, int>> temp;
        for(int j = 0; j < cur.size(); j++){
            int l = max(0, cur[j].first - K*(t-curTime)); int r = min(N, cur[j].second + K*(t-curTime));
            if(a <= l && r <= b) continue;
            if(l < a && b < r){
                temp.push_back({l, a-1});
                temp.push_back({b+1, r});
            }
            else if(l < a){ 
                temp.push_back({l, min(a-1, r)});
            }
            else if(b < r){
                temp.push_back({max(l, b+1), r});
            }
        }
        if(temp.size() == 0){
            cout << "NO\n";
            return 0;
        }
        cur.clear(); curTime = t;
        int l = temp[0].first, r = temp[0].second; 
        for(int j = 0; j < temp.size(); j++){
            if(temp[j].first > r){
                cur.push_back({l, r});
                l = temp[j].first; r = temp[j].second;
            } else {
                r = max(r, temp[j].second);
            }
        }
        cur.push_back({l, r});
    }
    cout << "YES\n";
}