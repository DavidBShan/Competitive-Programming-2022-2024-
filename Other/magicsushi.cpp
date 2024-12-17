#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s; map<char, vector<int>> prevLoc;
    for(int i = 0; i < s.size(); i++){
        if(prevLoc.find(s[i]) == prevLoc.end()) prevLoc[s[i]] = {i};
        else {
            //cout << s[i] << endl;
            for(int j = 0; j < prevLoc[s[i]].size(); j++){
                //cout << j << endl;
                for(int k = prevLoc[s[i]][j]; k < i; k++){
                    //cout << k << endl;
                    if(s.at(k+1) - s.at(k) == 1){
                        cout << "Sushi is Here!"; return 0;
                    }
                }
            }
            prevLoc[s[i]].push_back(i);
        }
    }
    cout << "Better Luck Next Time.";
}