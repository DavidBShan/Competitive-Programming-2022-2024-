#include <bits/stdc++.h>
using namespace std;
vector<long long> biVec;
void decToBi(long long n){
	long long i = 0, num = n;
	while(n != 0){
		biVec.push_back(n%2);
		n = n / 2;
	}
}

int main(){
    long long N; cin >> N;
    decToBi(N);
    for(long long i = 0; i < biVec.size();i++){
        cout << "1";
    }
}