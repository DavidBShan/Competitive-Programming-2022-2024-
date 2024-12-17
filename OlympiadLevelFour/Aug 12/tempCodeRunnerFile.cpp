#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int n, m, c, arr[MM];
deque<int> mx, mi;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> c; bool found = false;
    for(int l = 1, r = 1; r <= n; r++){
        cin >> arr[r];
        while(l <= r-m){
            if(mx.front() == l) mx.pop_front();
            if(mi.front() == l) mi.pop_front();
            l++;
        }

        while(!mx.empty() && arr[mx.back()] <= arr[r]) mx.pop_back();
        while(!mi.empty() && arr[mi.back()] >= arr[r]) mi.pop_back();
        mx.push_back(r); mi.push_back(r);

        if(r>=m && arr[mx.front()] - arr[mi.front()] <= c){
            cout << r - m + 1 << endl;  found=true;
        }
    }   
    if(!found) cout << "NONE" << endl;
}