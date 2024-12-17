#include <bits/stdc++.h>
using namespace std;
vector<int> LIS;

int main(){
    map<char,int> charMap {{'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},{'h',8},{'i',9},{'j',10},{'k',11},{'l',12},{'m',13},{'n',14},{'o',15},{'p',16},{'q',17},{'r',18},{'s',19},{'t',20},{'u',21},{'v',22},{'w',23},{'x',24},{'y',25},{'z',26}};

    string proc; cin >> proc;int x;
    for(int i = 0; i < proc.size();i++){
        x = charMap[proc[i]];
        if(LIS.empty()||LIS.back()< x) LIS.push_back(x);
        else *lower_bound(LIS.begin(), LIS.end(), x) = x;
    }
    cout << 26-LIS.size()<<endl;
}