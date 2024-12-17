#include<bits/stdc++.h>
using namespace std;

int main(){
    string A; string B; cin >> A >> B; bool good = true; int proc; int curDist;
    curDist = ((A.at(0) - B.at(0)<0)?A.at(0) - B.at(0)+26:A.at(0) - B.at(0));
    for(int i = 0; i < A.length();i++){
        proc = ((A.at(i) - B.at(i)<0)?A.at(i) - B.at(i)+26:A.at(i) - B.at(i)); 
        if(proc!=curDist){
            good = false; break; 
        }
    }
    cout << ((good==true)?"Yes":"No");
}