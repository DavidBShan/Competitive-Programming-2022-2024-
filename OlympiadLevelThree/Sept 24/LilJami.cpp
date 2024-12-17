#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, Q; cin >> N>>K; vector<int> cups; cups.resize(N,0); int add, a, b;
    for(int i = 0; i < K; i++){
        cin >> add;
        cups[add] += 1;
        cups[add + 1] -= 1;
    }
    cin >> Q;
    for(int i = 0; i < K;i++){
        cout << cups[i]<<endl;
    }
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << cups[b]+cups[a];
    }
}