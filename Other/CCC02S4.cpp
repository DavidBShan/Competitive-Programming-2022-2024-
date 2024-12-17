#include <bits/stdc++.h>
using namespace std;

int main(){
    int M, N, ans = 0; cin >> M >> N;
    string names[N]; int times[N], bestTime[N], groupCount[N];
    for(int i = 0; i < N;i++){
        cin >> names[i] >> times[i];
    }
    memset(groupCount, -1, sizeof groupCount);
    for(int i = 0; i < N+1;i++){ bestTime[i] = 1000000000; }
    bestTime[0] = 0, groupCount[0] = 0;
    for(int i = 0; i < N+1;i++){
        int cur = 0;
        for (int j = 1 ; j <= M && i + j - 1 < N ; j++)
	    {
            cur = max(cur, times[i + j - 1]);
            if (bestTime[i] + cur < bestTime[i + j]){
                bestTime[i + j] = bestTime[i] + cur;
                groupCount[i + j] = j;
            }
	    }
    }
    cout << "Total Time: " << bestTime[N]<<endl;
    int line[N+1], k = N, x = 0, z = 0;
    while(groupCount[k]!=0){
        line[x++] = groupCount[k];
        k -= groupCount[k];
    }
    for(int i = x - 1; i >= 0; i--){
        for (int j = 0 ; j < line[i] ; j++) cout << names[z++] << " ";
        cout << endl;
    }
}