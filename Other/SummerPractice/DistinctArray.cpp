#include <bits/stdc++.h>
using namespace std;
map<long long, int> mp;
int main(){
    int N; cin >> N;
    for(int i = 0, temp; i < N; i++){
        cin >> temp; 
        if(mp.find(temp)!=mp.end()){
            cout << "NO";
            return 0;
        }
        mp[temp] = 1;
    }
    cout << "YES";
}