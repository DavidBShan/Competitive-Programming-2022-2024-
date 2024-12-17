#include <bits/stdc++.h>
using namespace std;
int N; map<string, bool> visited; map<string, vector<string>> graph; string name;
bool hasLoop(string start, string par){
    visited[start] = true; 
    for(string name: graph[start]){
        if(visited[name]==true&&name!=par) return {name,};
        if(!visited[name]) hasLoop(name, start);
    }
    return false;
}
int main(){
    
}