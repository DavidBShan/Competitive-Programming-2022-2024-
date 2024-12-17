#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    string temp; int tempNum;
    vector<pair<int, string>> vec;
    for(int i = 0; i < N; i++){
        cin >> temp >> tempNum;
        vec.push_back({tempNum, temp});
    }
    sort(vec.begin(), vec.end());
    cout << vec.at(N/2).second;
}