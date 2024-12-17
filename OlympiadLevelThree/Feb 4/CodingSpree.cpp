#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T; cin >> N >> T;
    int problem[N][2]; int knapsack[N][T]; int bef; int aft; int curW; int rem;
    for(int i = 0; i < N;i++){
        cin >> problem[i][1] >> problem[i][0];
    }
    for(int i = 0;i<N;i++) knapsack[i][0] = 0;
    for(int i=  0; i<T;i++) knapsack[0][i] = 0;
    for(int i = 1; i <N;i++){
        for(int j = 1; j<T;j++){
            bef = knapsack[i-1][j];
            aft = 0; curW = problem[i-1][0];
            if(j>=curW){
                aft = problem[i-1][1];
                rem = j-curW;
                aft = knapsack[i-1][rem-1];
            }
            knapsack[i][j] = max(bef,aft);
        }    
    }
    cout << knapsack[N-1][T-1];
}