#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    vector<double> vec; bool flag = false;
    for(int i = 0, a, b; i < N; i++) {cin >> a >> b; vec.push_back(sqrt(pow(a,2)+ pow(b,2)));}
    sort(vec.begin(), vec.end());
    for(int i = 0; i < Q; i++){
        double r; cin >> r;
        int upper = upper_bound(vec.begin(), vec.end(), r)-vec.begin();
        cout << upper << "\n";
    }
}