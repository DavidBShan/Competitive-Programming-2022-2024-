#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; 
    string john = "moo"; string bessie;
    for(int i =1; i < min(400,N);i++){
        john+="moo";
    }
    cin >> bessie;
    if(john.find(bessie)==string::npos) cout <<"no";
    else cout << "yes";
}