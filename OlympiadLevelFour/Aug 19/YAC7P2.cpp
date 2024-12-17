#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T, N, M; cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M;
        int max = log10(N*M);
        if(N == 1 || M == 1 ){cout << "-1" << "\n"; continue;}
        int count = 2; 
        for(int i = 0; i < N; i++){
            int newCount = -1;
            for(int j = 0; j < M; j++){
                if(j==M-1 && i == N-1 && M%2==1){cout << string(max, ' ') << "1"; break;}
                else if(j==0 && i == N-1 && M%2==0) {cout << string(max, ' ') << "1" << " "; newCount++;continue;}
                if(i%2==0) cout << string(max-((int)log10(count)), ' ') << count << " ";
                else cout << string(max-((int)log10((i+1)*M-newCount)), ' ') << (i+1)*M-newCount << " ";
                count++; newCount++;
            }
            cout << "\n";
        }
    }
}