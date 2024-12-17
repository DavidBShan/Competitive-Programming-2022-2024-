#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, K, T;
double val[MM]; vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> T;
    for(int i = 0, a; i < K; i++){ cin >> a; v.push_back(a);}
    v.push_back(v[0]+N);
    int lo = 0, hi = 1;
    for(int i = 0; i < N; i++){
        int a, b;
        a = v[lo]; b = v[hi];
        if(i == v[hi]-1){ lo++; hi++;}
        //cout << a << " " << b << " ";
        double numDelayed = T-(i-a);
        //5
        int numCeiled = ceil(numDelayed/(double)(b-a));
        //5??
        int pos = (i+numCeiled*(b-a))%N;
        //cout << i << " " << pos << " " << numDelayed << " " << numCeiled << "\n";
        val[pos] = i;
    }
    for(int i = 0; i < N; i++){ cout << val[i] << " "; }
}