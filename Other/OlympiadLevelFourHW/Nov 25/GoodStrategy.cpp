#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, M;
set<pair<int, int>> freq;
int freqArr[MM]; bool done[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        freq.insert({0, i}); freqArr[i] = 0;
    }
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        if(a == 1){
            freq.erase({freqArr[b], b});
            done[b] = 1;
        }else{
            if(!done[b]){
                freq.erase({freqArr[b], b});
                freqArr[b]--;
                freq.insert({freqArr[b], b});
            }
        }
        if(freq.empty()){
            cout << "Make noise\n";
            continue;
        }
        cout << freq.begin()->second << " ";
        cout << freq.rbegin()->second << "\n";
    }
}