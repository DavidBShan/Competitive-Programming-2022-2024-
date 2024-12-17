#include <bits/stdc++.h>
using namespace std;
set<int> targets; map<int, int> nor, lft1, lft2, rgt1, rgt2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C; cin >> N >> C;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        targets.insert(x);
    }
    int pos = 0; int arr[C+3];
    for(int i = 1; i <= C; i++){
        char x; cin >> x; arr[i] = x;
        if(x == 'L') pos --;
        else if(x == 'R') pos ++;
        else{
            if(targets.find(pos) != targets.end()) nor[pos]++;
            if(targets.find(pos-1) != targets.end()) lft1[pos-1]++;
            if(targets.find(pos-2) != targets.end()) lft2[pos-2]++;
            if(targets.find(pos+1) != targets.end()) rgt1[pos+1]++;
            if(targets.find(pos+2) != targets.end()) rgt2[pos+2]++;
        }
    }
    int ans = nor.size(); int p = 0; nor.clear();
    for(int i = 1; i <= C; i++){
        if(arr[i] == 'L') {
            ans = max(ans, (int)nor.size() + (int)rgt1.size() + (targets.count(p) && !nor.count(p) && !rgt1.count(p))); //if change L to F
            ans = max(ans, (int)nor.size() + (int)rgt2.size()); //if change L to R
            p--; //don't change
        }else if(arr[i] == 'R') {
            ans = max(ans, (int)nor.size() + (int)lft1.size() + (targets.count(p) && !nor.count(p) && !lft1.count(p))); //if change R to F
            ans = max(ans, (int)nor.size() + (int)lft2.size()); //if change R to L
            p++;
        }else {
            ans = max(ans, (int)nor.size() + (int)lft1.size()); //change F to L
            ans = max(ans, (int)nor.size() + (int)rgt1.size()); //change F to R
            if(lft1.count(p-1) && --lft1[p-1]==0) lft1.erase(p-1);
            if(lft2.count(p-2) && --lft2[p-2]==0) lft2.erase(p-2);
            if(rgt1.count(p+1) && --rgt1[p+1]==0) rgt1.erase(p+1);
            if(rgt2.count(p+2) && --rgt2[p+2]==0) rgt2.erase(p+2);
            if(targets.count(p)) { nor[p]++; lft1.erase(p); lft2.erase(p); rgt1.erase(p); rgt2.erase(p); }
        }
    }
    cout << ans;
}