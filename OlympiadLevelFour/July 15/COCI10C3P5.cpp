#include <bits/stdc++.h>
using namespace std;
const int MM =  300005;
int N; int a[MM], rit[MM], lft[MM], ans = 0;
vector<int> mx, mi;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){cin >> a[i];}
    a[N+1] = 1e9;
    for(int i = 1; i <= N+1; i++){
        while(!mx.empty()&&a[mx.back()]<=a[i]){
            rit[mx.back()] = i; mx.pop_back();
        }
        if(mx.empty()) lft[i] = 0;
        else lft[i] = mx.back();
        mx.push_back(i);
    }
    for(int i=1; i<=N; i++){
        ans += (long long)a[i]*(i - lft[i]) * (rit[i] - i);
    }
    a[N+1]=-1;
    for(int i = 1; i <= N+1; i++){
        while(!mi.empty()&&a[mi.back()]>=a[i]){
            rit[mi.back()] = i; mi.pop_back();
        }
        if(mi.empty()) lft[i] = 0;
        else lft[i] = mi.back();
        mi.push_back(i);
    }
    for(int i=1; i<=N; i++){
        ans -= (long long)a[i]*(i - lft[i]) * (rit[i] - i);
    }
    cout << ans;
}