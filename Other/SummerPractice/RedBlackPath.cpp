#include <bits/stdc++.h>
using namespace std;

int main(){
    long long W, L;
    cin >> W >> L; char inp; long long arr[W+1][L+1];
    long long dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool visited[W+1][L+1];
    memset(visited, 0, sizeof visited);
    for(long long i = 0; i < W; i++){
        for(long long j = 0; j < L; j++){
            cin >> inp; arr[i][j] = (inp=='#'?1:0);
        }
    }
    vector<pair<vector<pair<long long, long long>>, vector<pair<long long, long long>>>> vec; 
    queue<pair<long long, long long>> q;
    for(long long i = 0; i < W; i++){
        for(long long j = 0; j < L; j++){
            if(visited[i][j]==false) q.push({i, j});
            else continue;
            visited[i][j]= true;
            vector<pair<long long, long long>> redVec;
            vector<pair<long long, long long>> blackVec;
            if(arr[i][j]==1) redVec.push_back({i, j});
            else blackVec.push_back({i, j});
            while(!q.empty()){
                long long tempI = q.front().first; long long tempJ = q.front().second; q.pop();
                for(long long a = 0; a < 4; a++){
                    if(dir[a][0]+tempI<0 || dir[a][0]+tempI>=W) continue;
                    if(dir[a][1]+tempJ<0 || dir[a][1]+tempJ>=L) continue;
                    if((arr[dir[a][0]+tempI][dir[a][1]+tempJ]+arr[tempI][tempJ])!=1)continue;
                    if(visited[dir[a][0]+tempI][dir[a][1]+tempJ]) continue;
                    q.push({dir[a][0]+tempI, dir[a][1]+tempJ}); 
                    if(arr[dir[a][0]+tempI][dir[a][1]+tempJ]==1) redVec.push_back({i, j});
                    else blackVec.push_back({i, j});
                    visited[dir[a][0]+tempI][dir[a][1]+tempJ]=true;
                }
            }
            vec.push_back({redVec, blackVec});
        }
    }
    long long ans = 0;
    //cout << vec.size();
    for(long long i = 0; i < vec.size(); i++){
        //cout << vec.at(i).first.size() << " " << vec.at(i).second.size();
        ans+=(vec.at(i).first.size()*(vec.at(i).second.size()));
    }
    cout << ans << "\n";
}