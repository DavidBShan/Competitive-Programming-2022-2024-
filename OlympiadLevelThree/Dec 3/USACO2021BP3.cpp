#include <bits/stdc++.h>
using namespace std;
bool findQ(char listT[4][2],char key1, char key2){
    for(int i =0; i < 4;i++){
        if(listT[i][0]==key1&&listT[i][1]==key2) return true;
    }
    return false;
}
int main(){
    char CWL[4][2] = {{'N','E'},{'E','S'},{'S','W'},{'W','N'}};
    char CWCL[4][2] = {{'E','N'},{'S','E'},{'W','S'},{'N','W'}};
    int N, CW=0, CWC=0; cin >> N; string proc; bool CWF = false;
    for(int i = 0; i < N;i++){
        cin >> proc;
        for(int j = 0; j < proc.size()-2;j++){
            if(findQ(CWL, proc.at(j),proc.at(j+1))==true) CW++;
            else if(findQ(CWCL, proc.at(j),proc.at(j+1))==true) CWC++;
        }
        if(CW>CWC) cout << "CW"<<endl;
        else cout << "CCW"<<endl;
        CW = 0; CWC = 0; 
    }
}