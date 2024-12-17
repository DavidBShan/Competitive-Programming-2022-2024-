#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<char> stk; string c4, org;
    cin >> org >> c4; bool flag = true;
    for(int i = 0; i < org.length(); i++){
        stk.push_back(org[i]);
        if(stk.size()>=c4.length()){
            for(int i = 1; i <= c4.length(); i++){
                if(stk.at(stk.size()-i)!=c4[c4.length()-i]){
                    flag = false;
                    break;
                }
            }
            if(flag==true){
                for(int i = 0; i < c4.length(); i++){
                    stk.pop_back();
                }
            }
        }
        flag = true;
    }
    if(stk.size()!=0){
        for(int i = 0; i < stk.size(); i++){
            cout << stk.at(i);
        }
    }else{
        cout << "FRULA";
    }
}