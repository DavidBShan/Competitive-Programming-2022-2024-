#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; set<int> row[N+1], col[N+1]; bool ans = true;
    char temp; vector<char> topRow, leftCol;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> temp;
            if(i==1) topRow.push_back(temp);
            if(j==1) leftCol.push_back(temp);
            if(row[i].find(temp) != row[i].end()) ans = false;
            else row[i].insert(temp);
            if(col[j].find(temp) != col[j].end()) ans = false;
            else col[j].insert(temp);
        }
    }
    if(!ans) cout << "No" << endl;
    else if(is_sorted(begin(topRow), end(topRow)) && is_sorted(begin(leftCol), end(leftCol))) cout << "Reduced" << endl;
    else cout << "Latin" << endl;
}