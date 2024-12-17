#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; long long sum = 0; string line;
    for(int i = 0; i < N;i++){
        cin >> line;
        for(int j = 0; j < line.size();j++){
            sum+=(int)line.at(j);
        }

        if(sum %3==0) cout << "yes"<<endl;
        else cout << "no"<<endl;
        sum = 0;
    }
}