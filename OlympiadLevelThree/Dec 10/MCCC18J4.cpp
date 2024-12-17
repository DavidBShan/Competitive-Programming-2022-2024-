#include <bits/stdc++.h>
using namespace std;
vector<char> topRow; vector<char> leftCorner;
int N; 
bool isLatin(){
    set<int> rows[N]; set<int> columns[N]; char temp; bool ans = true;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            cin >> temp; 
            if(i==0) topRow.push_back(temp);
            if(j==0) leftCorner.push_back(temp);
            if(rows[i].find(temp)!=rows[i].end()) ans = false;
            else rows[i].insert(temp);
            if(columns[j].find(temp)!=columns[j].end()) ans = false;
            else columns[j].insert(temp);
        }
    }
    return ans;
}
int main(){
    cin >> N;
    if(!isLatin()) cout << "No"<<endl;
    else{
        if(is_sorted(begin(topRow),end(topRow))&&is_sorted(begin(leftCorner),end(leftCorner))) cout << "Reduced"<<endl;
        else cout << "Latin"<<endl;
    }
}