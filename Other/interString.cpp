#include <bits/stdc++.h>
using namespace std;
set<string> allPerm;
void fun(deque<char> q1, deque<char> q2, string cur){
    if(q1.empty() && q2.empty()){
        allPerm.insert(cur);
        return;
    }
    if(!q1.empty()){
        char c = q1.front(); q1.pop_front();
        fun(q1, q2, cur+c); q1.push_front(c);
    }
    if(!q2.empty()){
        char c = q2.front(); q2.pop_front();
        fun(q1, q2, cur+c); q2.push_front(c);
    }   
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    deque<char> q1, q2; string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) q1.push_back(s1[i]);
    for(int i = 0; i < s2.size(); i++) q2.push_back(s2[i]);
    fun(q1, q2, "");
    for(auto i : allPerm) cout << i << endl;
}