#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    long long n, q; cin>>n>>q;
    vector<pair<int, int>>one; vector<pair<int, int>>two; vector<pair<int, int>>three;
    for(long long i = 0; i<n; i++){
        long long x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        one.push_back({x1, y1});
        two.push_back({x2, y2});
        three.push_back({x3, y3});
    }
    while(q--){
        ll a, b;

        cin>>a>>b;
        ll counter =0;
        for(ll i = 0; i<n; i++){
            ll x, y;
            x = a;
            y = b;
            ll x1, y1, x2, y2, x3, y3;
            bool hflip = false;
            bool vflip = false;
            x1 = one[i].first;
            y1 = one[i].second;
            x2 = two[i].first;
            y2 = two[i].second;
            x3 = three[i].first;
            y3 = three[i].second;
            ll xdiff = 0 - x1;
            ll ydiff = 0 - y1;
            //add xdiff to get to 0
            x1 += xdiff;
            x2 += xdiff;
            x3 += xdiff;
            y1 += ydiff;
            y2 += ydiff;
            y3 += ydiff;

            if(y2 <0 || y3 < 0){
                vflip = true;
                y2 *= -1;
                y3 *= -1;
            }
            if(x2 <0 || x3 < 0){
                hflip = true;
                x2 *= -1;
                x3 *= -1;
            }

            x += xdiff;
            y += ydiff;
            if(vflip)y *= -1;
            if(hflip)x *= -1;

            if(x >= 0 && y>= 0 && y*x3 <= (-1*y2)*x + y2*x3){
                counter++;
            }
        }
        cout<<counter<<endl;
    }
}