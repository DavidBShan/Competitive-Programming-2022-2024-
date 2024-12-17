#include <bits/stdc++.h>
using namespace std;
int N;
set<vector<int>> s;
int fun (int num, int lar, vector<int> allCur){
    if (num == 0){
        if (s.find(allCur) == s.end()) s.insert(allCur);
        return 0;
    }
    for(int i = lar; i <= num; i++){
        vector<int> cur = allCur;
        cur.push_back(i);
        fun(num-i, i, cur);
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    fun(N, 1, vector<int>(0));
    for(vector<int> i: s){
        if(i.size() == 1) continue;
        cout << N << "=" << i[0];
        for(int j = 1; j < i.size();j++) cout << "+" << i[j];
        cout << "\n";
    }
    cout << "total=" << s.size()-1;
}