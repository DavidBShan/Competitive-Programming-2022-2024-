#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; long long arr[N+1];
    vector<pair<long long, long long>> stk;
    long long ans = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++){
        while(!stk.empty()&&stk.back().first<arr[i]){
            ans+=stk.back().second;
            stk.pop_back();
        }if(!stk.empty() && stk.back().first==arr[i]){
            ans+=stk.back().second;
            stk.back().second++;
        }else{
            stk.push_back({arr[i], 1});
        }if(stk.size()>1){
            ans++;
        }
    }
    cout << ans;
}