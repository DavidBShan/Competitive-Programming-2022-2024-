#include <bits/stdc++.h>
using namespace std;
int const MM = 1003;
int main(){
    int N; cin >> N; map<string, int> freq;int graphX[MM], graphY[MM]; long long d;
    fill(graphX,graphX+MM,0);fill(graphY,graphY+MM,0);
    for(int i = 0; i < N;i++){
        cin >> graphX[i]>>graphY[i];
        for(int j = 0, mx, my; j <i;j++){
            mx = graphX[j]+graphX[i]; my = graphY[j]+graphY[i]; d = (graphX[j]-graphX[i])*(graphX[j]-graphX[i])+(graphY[j]-graphY[i])*(graphY[j]-graphY[i]);
            freq[to_string(mx)+","+to_string(my)+","+to_string(d%10000)]++;
        }
    }
    int ans = 0;
    for(auto const& [key, val]: freq){
        ans+= val*(val-1)/2;
    }  
    cout << ans;
}