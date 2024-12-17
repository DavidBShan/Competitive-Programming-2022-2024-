#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, D; cin >> N >> D; vector<vector<int>> detonations;
    vector<int> temp;
    int val, prevVal; cin >> prevVal; temp.push_back(prevVal);
    for(int i = 0; i < N-1; i++){
        cin >> val;
        if(abs(val - prevVal) <= D)
            temp.push_back(val);
        else{
            detonations.push_back(temp);
            temp.clear();
            temp.push_back(val);
        }
        prevVal = val;
    }
    if(temp.size() > 0) detonations.push_back(temp);
    cout << detonations.size();
    // cout << "DAMN";
    // for(auto x : detonations){
    //     cout << endl;
    //     for(auto y : x){
    //         cout << y << " ";
    //     }
    // }
    // cout << "UNDAMN";
    int maxSize = 0;
    for(auto x : detonations){
        if(x.size() > maxSize) maxSize = x.size();
    }
    cout << endl << maxSize;
}