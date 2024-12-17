#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;vector<int> neigh; int temp; vector<double> size; double minN = 1000000001;
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> temp; neigh.push_back(temp);
    } sort(neigh.begin(), neigh.end());
    for(int i = 1; i < N-1;i++){
        minN = min(minN,abs(((double)(neigh[i]-neigh[i-1])/2))+abs(((double)(neigh[i+1]-neigh[i])/2)));
    }cout << fixed << setprecision(1) << minN;
}