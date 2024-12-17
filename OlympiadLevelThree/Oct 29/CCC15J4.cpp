#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> time; map<int,int> sum;int N, curTime = 0, person; cin >> N; char op; map<int,int> temp;
    vector<pair<int,int>> friendL;
    for(int i = 0; i < N;i++){
        cin >> op >> person;
        if(op == 'R'){
            time[person] = curTime;
            temp[person]=sum[person];
            sum[person] = -1;
            curTime++;
        }else if(op == 'S'){
                if(time.find(person)!=time.end()){
                    if(sum.find(person)!=sum.end()){
                            sum[person]= temp[person]+curTime-time[person];
                            time[person] = -1;
                            curTime++;
                    } 
                    else{
                            sum[person] = curTime-time[person];
                            time[person] = -1;
                            curTime++;
                    }
                }else{
                    sum[person] = -1;
                    curTime++;
                }
        }else{
            curTime+=person;
            curTime--;
        }
    }
    for (auto const& [key, val] : sum) friendL.push_back({key,val});
    sort(friendL.begin(), friendL.end());
    for(int i = 0; i < friendL.size();i++) cout << friendL[i].first << " " <<friendL[i].second << endl;
}