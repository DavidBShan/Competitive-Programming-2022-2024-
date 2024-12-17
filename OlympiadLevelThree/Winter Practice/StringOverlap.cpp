#include<bits/stdc++.h>
using namespace std;

int main(){
    string A; cin >> A; string B; cin >> B; int len = min(A.length(),B.length()); int AFirstMax = 1; int BFirstMax = 1;
    /*A pre B suf*/
    for(int i = 2; i<=len;i++){
        if(A.substr(0,i).compare(B.substr(B.length()-i,i))==0) AFirstMax = i;
    }
    /*A suf B pre*/
    for(int i = 2; i<=len;i++){
        if(A.substr(A.length()-i,i).compare(B.substr(0,i))==0) BFirstMax = i;
    }
    cout << max(AFirstMax,BFirstMax);
}