#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; string proc; int counter = 0; bool flag = true;
    for(int i = 0; i < N;i++){
        cin >> proc;
        for(int j = 0; j < proc.size();j++){
            if(proc[j]=='('){
                counter++;
            }else if(proc[j]==')'){
                counter--;
            }
            if (counter < 0){flag = false; break;}
        }
        cout << (counter==0 && flag == true?"YES":"NO") << endl;
        counter = 0; flag = true;
    }
}