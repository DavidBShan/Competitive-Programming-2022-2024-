#include <bits/stdc++.h>
using namespace std;
stack<char> sven;
int R, N, A=0, B=0;

int points(char sym, stack<char>friends[]){
    int ans=0;
    for(int i = 0; i < N; i++){
        if(sym=='S'&&friends[i].top()=='P') ans+=2;
        else if(sym=='S'&&friends[i].top()=='S')ans++;
        else if(sym=='P'&&friends[i].top()=='R')ans+=2;
        else if(sym=='P'&&friends[i].top()=='P')ans++;
        else if(sym=='R'&&friends[i].top()=='S')ans+=2;
        else if(sym=='R'&&friends[i].top()=='R')ans++;
    }
    return ans;
}

int main(){
    cin >> R; char temp;
    for(int i = 0; i < R; i++){
        cin >> temp; sven.push(temp);
    }
    cin >> N; stack<char>friends[N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < R; j++){
            cin >> temp;
            friends[i].push(temp);
        }
    }
    for(int i = 0; i < R; i++){
        A+=points(sven.top(),friends); sven.pop();
        B+=max(points('R', friends), max(points('S', friends), points('P', friends)));
        for(int j = 0; j < N; j++){
            friends[j].pop();
        }
    }
    cout << A << endl << B;
}