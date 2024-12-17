#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, x, y, W, countDis, dispenser, temp, tempAnt; int antMove = 0; bool sacrifice = false; 
    int visited[101]; memset(visited, -1, sizeof visited); visited[1] = 1;cin >> N >> M;
    map<int, vector<int>> graph; vector<int> ant; vector<int> people; people.push_back(1); int start = 1, end = N;
    for(int i = 1; i <= M;i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    } cin >> W; countDis = W;
    for(int i = 0; i < W;i++){
        cin >> dispenser; 
        if(dispenser!=1){
            ant.push_back(dispenser); visited[dispenser] = -2;
        }
    }while(!people.empty()){//problem: if both ant and people que have the same value, people queue needs to be deleted.
        temp = people.front(); people.erase(people.begin());
        if(visited[temp]%4==1&&visited[temp]/4!=antMove){
            antMove++; W = 0;
            for(int i = 0; i < countDis;i++){
                tempAnt = ant.front(); ant.erase(ant.begin());
                for(int j = 0; j < graph[tempAnt].size();j++){
                    if (visited[graph[tempAnt][j]] == -1){
                        visited[graph[tempAnt][j]] = -2; ant.push_back(graph[tempAnt][j]); W++;
                        if(find(people.begin(), people.end(), graph[tempAnt][j]) != people.end() ){
                            people.erase(find(people.begin(), people.end(), graph[tempAnt][j]));
                        }
                    }
                } countDis = W;
            }
        }for(int i = 0; i < graph[temp].size();i++){
            if(visited[graph[temp][i]]==-1){
                people.push_back(graph[temp][i]); visited[graph[temp][i]] = visited[temp]+1;
            }
        }
    }if(visited[end]==-1||visited[end]==-2) cout << "sacrifice bobhob314";
    else cout << visited[end];
}