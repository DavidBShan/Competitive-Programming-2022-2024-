#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;  cin >> N; double arr[N+1]; vector<pair<int, int>> stk;
    arr[0] = -1; long long ans = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++){
        while(!stk.empty()&&stk.back().first < arr[i]){
            ans+=stk.back().second;
            stk.pop_back(); 
        }
        if(!stk.empty()&&stk.back().first > arr[i]){
            ans++;
        }
        if(!stk.empty()&&stk.back().first!=arr[i-1]&&arr[i-1]>arr[i]){
            ans++;
        }
        if(!stk.empty()&&stk.back().first == arr[i]){
            ans+=stk.back().second;
            stk.back().second++;
            if(stk.size()>=2&&stk.at(stk.size()-2).first>arr[i]){
                ans++;
            }
        }else{
            stk.push_back({arr[i], 1});
        }
    }
    cout << ans;
}

