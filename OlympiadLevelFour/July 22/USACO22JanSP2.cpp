#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; long long arr[N+1], ans = 0; vector<long long> stk;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }for(int i = 1; i <= N; i++){
        while(!stk.empty()&&arr[stk.back()]<=arr[i]){
            ans+=i-stk.back()+1;
            stk.pop_back();
        }if(!stk.empty()){
            ans+=i-stk.back()+1;
        }
        stk.push_back(i);
    }
    cout << ans;
}