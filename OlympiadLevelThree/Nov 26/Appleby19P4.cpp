#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MaxSize = 2000;
int N, x[MaxSize], y[MaxSize], ans; set<pi> s;
int main(){
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
        s.insert({x[i], y[i]});
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(s.count({x[i], y[j]}) && s.count({x[j], y[i]})){
                ans = max(ans, abs(x[i]-x[j])*abs(y[i]-y[j]));
            }
        }
    }
    cout << ans << endl;
}