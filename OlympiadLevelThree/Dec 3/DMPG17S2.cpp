#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, Q, temp1, temp2, test;bool flag = false; cin >> N >> Q; string Query;
    int vis[N]; map<int,vector<int>> graph; queue<int> q;
    for(int i = 0; i < Q;i++){
        cin >> Query>>temp1 >> temp2;
        if(Query == "A") {
            graph[temp1].push_back(temp2); graph[temp2].push_back(temp1);
        }else{
            q= queue<int>(); q.push(temp1); memset(vis,0,sizeof vis);
            while(!q.empty()){
                test = q.front(); q.pop();
                for(int c:graph[test]){
                    if(vis[c]==0){
                        if(c==temp2){
                            cout << "Y"<<endl; flag = true; break;
                        }else{
                            q.push(c); vis[c] = 1;
                        }
                    }
                }
                if (flag == true){
                    break;
                }
            }
            if(flag == false) cout << "N"<<endl;
            flag = false;
        }
    }
}