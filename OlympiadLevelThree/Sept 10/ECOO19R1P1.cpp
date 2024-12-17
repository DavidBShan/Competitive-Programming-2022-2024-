#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, D;
    int tempN; int tempDate; int count=0; int curCheck = 0;
    vector<int> eventDate;
    for(int i = 0; i < 10;i++){
        cin >> N >> M >> D;
        tempN = N;
        for(int j = 0; j < M;j++){
            cin >> tempDate;
            eventDate.push_back(tempDate);
        }
        sort(eventDate.begin(), eventDate.end());
        for(int j = 1; j <= D;j++){
            if(tempN==0){
                count++;
                tempN=N;
            }
            if (curCheck < M)
            {
                while (eventDate[curCheck] == j)
                {
                    curCheck++;
                    tempN++;
                    N++;
                    if (curCheck >= M)
                    {
                        break;
                    }
                }
            }
            tempN--;
        }
        cout << count << endl;
        count = 0;
        curCheck = 0;
        eventDate.clear();
    }
}
