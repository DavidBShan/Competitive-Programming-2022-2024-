#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; string proc; int count = 0;
    cin >> t;
    for(int i = 0; i < t;i++){
        cin >> proc;
        for(int j = 0; j<proc.size();j++){
            if(proc[j]=='-') continue;
            if(count==10) break;
            if(isdigit(proc[j])) {cout << proc[j]; count++;}
            else if(proc[j]=='A'||proc[j]=='B'||proc[j]=='C') {cout << '2'; count++;}
            else if(proc[j]=='D'||proc[j]=='E'||proc[j]=='F') {cout << '3'; count++;}
            else if(proc[j]=='G'||proc[j]=='H'||proc[j]=='I') {cout << '4'; count++;}
            else if(proc[j]=='J'||proc[j]=='K'||proc[j]=='L') {cout << '5'; count++;}
            else if(proc[j]=='M'||proc[j]=='N'||proc[j]=='O') {cout << '6'; count++;}
            else if(proc[j]=='P'||proc[j]=='Q'||proc[j]=='R'||proc[j]=='S') {cout << '7'; count++;}
            else if(proc[j]=='T'||proc[j]=='U'||proc[j]=='V') {cout << '8'; count++;}
            else if(proc[j]=='W'||proc[j]=='X'||proc[j]=='Y'||proc[j]=='Z') {cout << '9'; count++;}
            if(count==3||count==6) cout << '-';
        }
        count = 0;
        cout << endl;
    }
}