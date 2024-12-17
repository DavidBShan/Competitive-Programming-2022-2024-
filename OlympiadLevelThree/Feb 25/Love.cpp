#include <bits/stdc++.h>
using namespace std;
const int MM = 10005;
long long sumArr[4][MM];
int main(){
    string str; cin >> str;
    int len = str.length();
    for(int i = 0; i < 4;i++) sumArr[i][0]=0;
    for(int i = 1; i <= len;i++){
        for(int j = 0; j < 4;j++) sumArr[j][i] = sumArr[j][i-1];
        if(str[i-1]=='l') sumArr[0][i]  = sumArr[0][i-1]+1;
        else if(str[i-1]=='o'){
            sumArr[1][i] += sumArr[0][i];
        }else if(str[i-1] == 'v'){
            sumArr[2][i] += sumArr[1][i];
        }else if(str[i-1] == 'e'){
            sumArr[3][i] += sumArr[2][i];
        }
    }
    cout << sumArr[3][len];
}