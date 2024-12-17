#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> food; 
int curSour, curBitter; int curDif = INT_MAX,N, start;  vector<int> difV;
void fun(int add){
    if(add >= N) return;
    fun(add);
    /*if(abs((curSour*food[add].first)-(curBitter+food[add].second))<curDif){
        curSour*=food[add].first; curBitter+=food[add].second;
        curDif = abs(curSour-curBitter);
    }*/
    curSour*=food[add].first; curBitter+=food[add].second;
    curDif = abs(curSour-curBitter);
    add++;
    fun(add);
}
int main(){
    cin >> N;
    for(int i = 0, so, bi; i < N;i++){
        cin >> so >> bi;
        food.push_back({so,bi});
    }
    for(int i = 0; i < N;i++){
        start = i; curSour = 1; curBitter = 0;
        fun(start);
    }
    sort(difV.begin(), difV.end());
    cout << difV[0];
}