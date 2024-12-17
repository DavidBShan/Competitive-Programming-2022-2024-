#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0; i < 5;i++){
        map<string,string> parent; map<string,int> cityC; int numC = 1, countOp;char op; string cityF,cityS; 
        cin >> countOp; 
        for(int i = 0; i < countOp;i++){
            cin >> op >> cityF >> cityS;
            if(!parent.count(cityF)){parent[cityF] = cityF; cityC[cityF] = 1;}
            if(!parent.count(cityS)){parent[cityS] = cityS; cityC[cityS] = 1;}
            if(op=='p'){
                if(cityC[cityF]>=cityC[cityS]){
                    parent[cityS]=parent[cityF]; cityC[cityF]++; 
                }else{
                    parent[cityF]=parent[cityS]; cityC[cityS]++;
                }
            }else{
                cout <<(parent[cityF]==parent[cityS]?"connected":"not connected")<<endl;
            }
        }
    }
}