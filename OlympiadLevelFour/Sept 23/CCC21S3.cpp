#include <bits/stdc++.h>
using namespace std;
int N, mn = 1e9+7, mx = -1, ans = 1e9+7; vector<array<int, 3>> vec;

int solve(int pos){
    int tempAns = 0;
    for(int i = 0; i < vec.size(); i++){
        tempAns+=vec.at(i)[1]*max(0, abs(pos-vec.at(i)[0])-vec.at(i)[2]);
    }
    //ans = min(tempAns, ans);
    return tempAns;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0, p, w, d; i < N; i++){
        cin >> p >> w >> d; mn = min(mn, p); mx = max(mx, p); vec.push_back({p, w, d});
    }
    //cout << mn << " "<< mx<< endl;
    while(mn < mx){
        int mid = (mn+mx)/2;
        int sumL = solve(mid);
        int sumR = solve(mid+1);
        if(sumL > sumR){
            mn = mid+1;
        }else{
            mx = mid-1;
        }
    }
    cout << mn << endl;
}