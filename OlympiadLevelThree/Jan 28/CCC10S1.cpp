#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; vector<vector<string>> computer;
    string name;
    for(int R,S,D,i = 0; i< N;i++){
        cin >> name >> R >> S >> D;
        computer.push_back({name,to_string(2*R+3*S+D)});
    } 
    sort(computer.begin(),computer.end(),[](vector<string>& a, vector<string>& b) {
      if(a[1]!=b[1])  return stoi(a[1])>stoi(b[1]);
      else return a[0]<b[0];
    });
    if(N == 0) cout << endl;
    else if(N==1) cout << computer[0][0]<<endl;
    else cout << computer[0][0]<<endl<<computer[1][0]<<endl;
}