#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int numF; int numE; int numT; string temp1; string temp2; int count = 0; map<string, set<string>> friends;
    map<string, set<string>> enemies; string ArrProc[3]; set<string> temp;

    cin >> numF;
    for(int i = 0; i < numF;i++){
        cin >> temp1 >> temp2;
        friends[temp1].insert(temp2);
        friends[temp2].insert(temp1);
    }

    cin >> numE;
    for(int i = 0; i < numE;i++){
        cin >> temp1>> temp2;
        enemies[temp1].insert(temp2);
        enemies[temp2].insert(temp1);
    }

    cin >> numT;
    for(int i = 0; i < numT; i++){
        for(int j = 0; j < 3;j++){
            cin >> ArrProc[j];
        }
        for(int j = 0; j < 3;j++){
            temp = friends[ArrProc[j]];
            for (auto &str : temp)
            {
                for(int z = 0; z <3;z++){
                    if(z==j){
                        continue;
                    }else{
                        if(str!=ArrProc[z]){
                            
                        }
                    }
                }
                if (str != ArrProc[2])
                {
                    friends[ArrProc[2]].erase(str);
                    friends[str].erase(ArrProc[2]);
                    count++;
                }
                if (str != ArrProc[1])
                {
                    friends[ArrProc[1]].erase(str);
                    friends[str].erase(ArrProc[1]);
                    count++;
                }
                if (str != ArrProc[0])
                {
                    friends[ArrProc[0]].erase(str);
                    friends[str].erase(ArrProc[0]);
                    count++;
                }
            }
        }

        for (int j = 0; j < 3; j++)
        {
            temp = enemies[ArrProc[j]];
            for (int z = 0; z < temp.size(); z++)
            {
                if (temp[z] == ArrProc[2] && temp[z] == ArrProc[1] && temp[z] == ArrProc[0])
                {
                    enemies[ArrProc[j]].erase(enemies[ArrProc[j]].begin() + z);
                    count++;
                }
            }
        }
    }
    cout << count;
}