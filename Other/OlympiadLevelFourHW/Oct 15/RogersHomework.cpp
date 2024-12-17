#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> allTasks; int count = 0, cur;
    int N, x, y;cin >> N;
    for(int i = 0; i < N;i++){
        cin >> x >> y;
        allTasks.push_back({x,y});
    }
    sort(allTasks.begin(), allTasks.end());
    cur = allTasks[N-1].first;
    while(allTasks.size()>0){
        if(allTasks.back().first>cur){
            allTasks.pop_back();
        }else if(cur > allTasks.back().first){
            cur--;
        }else{
            cur--;
            count+=allTasks.back().second;
            allTasks.pop_back();
        }
    }
    cout << count;
}