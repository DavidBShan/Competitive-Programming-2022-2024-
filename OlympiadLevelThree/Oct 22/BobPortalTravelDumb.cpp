#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K,cur = 1; vector<int> order;
    cin >> N >> K;
    order.push_back(0);
    for(int i = 0,temp; i < N;i++){
        cin >> temp; order.push_back(temp);
    }for(int i = 0; i < K;i++){
        cur = order[cur];
    }
    cout << cur;
}