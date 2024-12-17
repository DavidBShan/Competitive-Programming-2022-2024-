#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2, base = 131;
char s[MM]; int K;
long long hsh[MM], pw[MM];
long long subHash(int L, int R){return hsh[R]-hsh[L-1]*pw[R-L+1];} 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    scanf("%s %d", s+1, &K); int len = strlen(s+1);
    pw[0] = 1; hsh[0] = 0;
    for(int i = 1; i <=len; i++){
        pw[i] = pw[i-1]*base;
        hsh[i] = hsh[i-1]*base + s[i];
    } 
    int bst = 1;
    for(int i = 2; i+K-1<=len; i++){
        if(s[i]<s[bst]) bst = i;
        else if(s[i] == s[bst]){
            int low = 0, high = K-1, curDif = 0;
            while(low<=high){
                int mid = (low+high)/2;
                if(subHash(i, i+mid)==subHash(bst, bst+mid))  low=mid+1;
                else{curDif=mid; high=mid-1;}
            }
            if(s[i+curDif]<s[bst+curDif]) bst=i;
        }
    }
    for(int i = bst; i < bst+K; i++) cout << s[i];
}