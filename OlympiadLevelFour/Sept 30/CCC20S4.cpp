#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int psaA[MM*2], psaB[MM*2], psaC[MM*2], ans = 1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    int N = str.size();
    str = str+str;
    memset(psaA, 0, sizeof(psaA)); memset(psaB, 0, sizeof(psaB)); memset(psaC, 0, sizeof(psaC));
    for(int i = 0; i < str.size(); i++){
        psaA[i+1]=psaA[i]; psaB[i+1]=psaB[i]; psaC[i+1]=psaC[i];
        if(str[i]=='A') {psaA[i+1]++;}
        else if(str[i]=='B') {psaB[i+1]++;}
        else {psaC[i+1]++;}

    }
    int totalA = psaA[str.size()]/2, totalB = psaB[str.size()]/2, totalC = psaC[str.size()]/2;
    for(int i = 1; i <= N; i++){
        int AinB, AinC, CinA, BinA, nonA, nonB, nonC;
        AinB = psaA[i+totalA+totalB-1]-psaA[i+totalA-1]; AinC = psaA[i+totalA+totalC-1]-psaA[i+totalA-1];
        CinA = psaC[i+totalA-1]-psaC[i-1]; BinA = psaB[i+totalA-1]-psaB[i-1];
        nonA = totalA-(psaA[i+totalA-1]-psaA[i-1]); nonB = totalB-(psaB[i+totalA+totalB-1]-psaB[i+totalA-1]); nonC = totalC-(psaC[i+totalA+totalC-1]-psaC[i+totalA-1]);
        ans = min(ans, min(nonA+nonB-min(AinB, BinA), nonA+nonC-min(AinC, CinA)));
    }
    cout << ans;
}