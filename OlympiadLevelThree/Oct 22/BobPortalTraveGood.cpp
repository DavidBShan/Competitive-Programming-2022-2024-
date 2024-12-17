#include <bits/stdc++.h>
using namespace std;
vector<int> order; vector<int> original;
set<int> contained; int extra = 0;
int start=1, N,temp; long long K;
void dfs(int s){
    if(original[s] ==start) return;
    if(contained.find(original[s])!=contained.end()){
        for(int i = 1; i < order.size();i++){
            if(original[s]==order[i]){
                extra = i; break;
            }
        }
        return;
    } 
    contained.insert(original[s]);
    order.push_back(original[s]);
    dfs(original[s]);
}
int main(){
    cin >> N >> K;
    order.push_back(0); original.push_back(0);
    for(int i = 0; i < N;i++){
        cin >> temp; original.push_back(temp);
    }
    contained.insert(original[1]);
    order.push_back(original[1]);
    dfs(1);
    if(((K-extra)%(order.size()-1-extra))==0){
        cout << order[order.size()-1-extra];
    }else{
        cout << order[(K-extra)%(order.size()-1-extra)];
    }
}