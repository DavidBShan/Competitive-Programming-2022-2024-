#include <bits/stdc++.h>
using namespace std;
int N; vector<pair<int, int>> vec; stack<int> stk;
int main(){
    cin >> N;
    for(int i = 0, x, y; i < N; i++){
        cin >> x >> y; vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    for(int i=N-1; i>=0; i--){
        int y = vec[i].second;
        if(stk.empty()||stk.top() < y) stk.push(y);
        else{
            int best = stk.top(); stk.pop();
            while(!stk.empty()&&stk.top()>=y){
                stk.pop();
            }
            stk.push(best);
        }
    }
    cout << stk.size();
}