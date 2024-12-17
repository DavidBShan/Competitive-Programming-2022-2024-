#include <bits/stdc++.h>
using namespace std;

string processInp(string numStr){
    if(numStr.size()==1) return numStr;
    else if(numStr[0]=='0') return processInp(numStr.substr(1));
    else return numStr;
}

bool compareFun(string a, string b)
{
    return a.size() < b.size()|| (a.size() == b.size() && a < b);
}

int main(){
    int N; cin >> N; string procStr; vector<string> allNum; string curNum = "";
    for(int i = 0; i < N;i++){
        cin >> procStr;
        for(int j = 0; j < procStr.size();j++){
            if(isdigit(procStr[j])) curNum.push_back(procStr[j]);
            else if (!isdigit(procStr[j])&&curNum!=""){
                allNum.push_back(processInp(curNum)); curNum = "";
            }
        }
        if(curNum!=""){
            allNum.push_back(processInp(curNum)); curNum = "";
        }
    }
    sort(allNum.begin(), allNum.end(), compareFun);
    for(string printNum:allNum) cout << printNum << endl;
}