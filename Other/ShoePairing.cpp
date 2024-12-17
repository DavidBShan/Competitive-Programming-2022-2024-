#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> leftShoes; vector<int> rightShoes; int N;

int minUgly() {
    int maxStrangeness = 0;
    for (int i = 0, j = 0; i < N; i++, j++) {
        if(leftShoes[j].first == -1) j++;
        int strangeness = leftShoes[j].first - rightShoes[i];
        maxStrangeness = max(maxStrangeness, strangeness);
    }
    return maxStrangeness;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; vector<int> ans(N+2);
    for(int i = 0, temp; i <= N; i++){
        cin >> temp;
        leftShoes.push_back({temp, i});
    }
    for(int i = 0, temp; i < N; i++){
        cin >> temp;
        rightShoes.push_back(temp);
    }
    sort(leftShoes.begin(), leftShoes.end());
    sort(rightShoes.begin(), rightShoes.end());
    for(int i = 0; i <= N; i++){
        pair<int, int> tempPair = leftShoes[i];
        leftShoes[i].first = -1;
        int minUgliness = minUgly();
        //cout << tempPair.first << " " << tempPair.second << " " << minUgliness << endl;
        //ans.insert(ans.begin() + tempPair.second, minUgliness);
        ans[tempPair.second] = minUgliness;
        leftShoes[i] = tempPair;
    }
    for(int i = 0; i <= N; i++){
        cout << ans[i] << " ";
    }
}