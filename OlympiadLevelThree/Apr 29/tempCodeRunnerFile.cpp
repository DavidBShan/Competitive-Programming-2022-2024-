#include <bits/stdc++.h>
using namespace std;
vector<int> biVec;
void decToBi(int n){
	int i = 0, num = n;
	while(n != 0){
		biVec.push_back(n%2);
		n = n / 2;
	}
}

int main(){
    int N; cin >> N;
    decToBi(N);
    cout << pow(2,biVec.size())-1;
}