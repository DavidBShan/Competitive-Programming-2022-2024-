#include <bits/stdc++.h>
using namespace std;
double threshold; long long N;
int check(long long x){
    long long lowY = x*(x+1)/2, highY = (x+1)*(x+2)/2;
    if(lowY<=threshold && highY<=threshold) return -1;
    else if(lowY<=threshold && highY>threshold) return 0;
    else return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; threshold = (double) N*(N-1)/4;
    long long lo = 0, hi = N, mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        int ret = check(mid);
        if(ret==0){ cout <<N-mid-1<<"\n"; break;}
        else if(ret<0){ lo = mid;}
        else{ hi = mid;}
    }
}