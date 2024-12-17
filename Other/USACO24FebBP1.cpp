#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+5;
long long dir[MM], cap[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m; cin >> n >> m;
    string s; cin >> s;
    for(long long i = 0; i < n; i++){
        char temp = s[i];
        if(temp == 'L') dir[i] = -1;
        else dir[i] = 1;
    }
    for(long long i = 0; i < n; i++) cin >> cap[i];
    long long loss = 0;
    for(long long i = 0; i < n; i++){
        if(dir[i%n] == 1 && dir[(i+1)%n] == -1){
            long long prev = (i-1+n)%n, nxt = (i+2)%n;
            long long prevCnt = 0, nxtCnt = 0;
            while(dir[prev] == 1){
                prevCnt+=cap[prev];
                prev--;
                if(prev < 0) prev += n;
            }
            while(dir[nxt] == -1){
                nxtCnt+=cap[nxt];
                nxt++;
                if(nxt >= n) nxt -= n;
            }
            loss += min(m, prevCnt) + min(m, nxtCnt);
        }
    }
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        sum+=cap[i];
    }
    cout << sum - loss << endl;
}