#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N; pair<int,int> arr[N+1];
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y; arr[i] = {x, y};
    }
    double sum = 0; double dif = 0;
    for(int i = 0; i < N; i++){
        if(i == N-1) {
            sum += arr[i].first*arr[0].second;
            dif += arr[i].second*arr[0].first;
        }else{
            sum += arr[i].first*arr[i+1].second;
            dif += arr[i].second*arr[i+1].first;
        }
    }
    cout << ceil(0.5*abs(sum-dif));
}