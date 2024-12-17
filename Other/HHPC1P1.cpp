#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, T; cin >> T;
    for(int j = 0; j < T; j++){
        int maxCount = 1, currentCount = 1; char cur, prev;
        vector<pair<pair<int, int>, pair<int, char>>> vec;
        bool damn = false;
        cin >> N >> prev; int st = 0, end = 0;
        for (size_t i = 0; i < N-1; i++) {
            cin >> cur;
            if (cur == prev) {
                currentCount++;
                end++;
                maxCount = std::max(maxCount, currentCount);
            } else {
                vec.push_back({{st, end}, {currentCount, prev}});
                currentCount = 1;
                st = i+1;
                end = i+1;
            }
            prev = cur;
        }
        vec.push_back({{st, end}, {currentCount, cur}});
        if(vec.size() < 3){
            if(maxCount == N) cout << maxCount << endl;
            else cout << maxCount+1 << endl;
            continue;
        }
        for(int i = 0; i < vec.size()-2; i++){
            if(vec[i+1].first.second == vec[i+1].first.first && vec[i].second.second == vec[i+2].second.second){
                if((vec[i].second.first + vec[i+2].second.first+1) > ((damn == true)?maxCount:maxCount+1)){
                    maxCount = vec[i].second.first + vec[i+2].second.first+1;
                    damn = true;
                }
            } 
        }
        if(maxCount == N) cout << maxCount << endl;
        else cout << ((damn == true)?maxCount:maxCount+1) << endl;
    }
}