#include <bits/stdc++.h>
using namespace std;
int N, M;
int main(){
    cin >> N >> M; map<int, bool> mp;
    vector<int> ans;
    for(int i = 0, temp; i < N; i++){
        cin >> temp; mp[temp] = true;
        if(mp.size()==M){ ans.push_back(temp); mp.clear(); }
    }
        for(int i = 1; i <= M; i++){
            if(mp.find(i)==mp.end()){
               ans.push_back(i); mp.clear(); break;
            }
        }
    
    cout << ans.size();
}