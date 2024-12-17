#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T; vector<int> stk, end;
    string temp;
    for(int i = 0, moves; i < T; i++){
        stk.clear(); end.clear();
        cin >> temp>>moves;
        //stk.push_back(1e9);
        for(int j = 0; j < temp.length(); j++){
            while(!stk.empty()&&moves&&(int(temp[j])-48) < stk[stk.size()-1]){
                //cout << stk[stk.size()-1];
                end.push_back(stk[stk.size()-1]); stk.pop_back();
                moves--;
            }
            stk.push_back(temp[j]-48);  
            //cout << stk[stk.size()-1];
        }
        while(!stk.empty()&&moves){ 
            end.push_back(stk.back());stk.pop_back(); 
            moves--;
        }
        sort(end.begin(), end.end());
        for(int j = 0; j<stk.size();j++) cout << stk.at(j);
        for(int j = 0; j<end.size(); j++) cout << end.at(j);
        cout << endl;
    }
}