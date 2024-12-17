#include <bits/stdc++.h>
using namespace std;

vector<int>biVec;

void decToBi(int n){
	int i = 0, num = n;
	while(n != 0){
		biVec.push_back(n&2);
		n = n / 2;
	}
}

int BiToDec(){
    int num = 1, ans = 0;
    for(int i = 0; i < biVec.size();i++){
        ans+=num*biVec[i];
        num*=2;
    }
    return ans;
}

int main(){
    int N; cin >> N;
    for(int i = 0, proc; i < N;i++){
        cin >> proc;
        biVec.clear();
        decToBi(proc);
        cout << BiToDec();
    }
}