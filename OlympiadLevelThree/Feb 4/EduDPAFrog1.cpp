#include <bits/stdc++.h>
using namespace std;
const long long MM = 10000000000;
int main(){
    int N; cin >> N; long long dis[N+1]; int weight[N+1];
    for(int i = 1;i<=N;i++){
        dis[i] = MM;
        cin >> weight[i];
    }
    dis[1] = 0; 
    dis[2] = abs(weight[1]-weight[2]);
    for(int i = 3;i<=N;i++){
        dis[i] = min(dis[i-2]+abs(weight[i-2]-weight[i]),dis[i-1]+abs(weight[i-1]-weight[i]));
    }
    cout << dis[N];
}