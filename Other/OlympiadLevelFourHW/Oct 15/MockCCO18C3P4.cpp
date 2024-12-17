#include <bits/stdc++.h>
using namespace std;
int N, Q; vector<int> arr;
int lookupMin[20000][20000], lookupMax[20000][20000];
void buildMin(){
    for (int i = 0; i < N; i++)
        lookupMin[i][0] = arr[i];
    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 0; (i + (1 << j) - 1) < N; i++) {
            if (lookupMin[i][j - 1] < lookupMin[i + (1 << (j - 1))][j - 1]) lookupMin[i][j] = lookupMin[i][j - 1];
            else lookupMin[i][j] = lookupMin[i + (1 << (j - 1))][j - 1];
        }
    }
}
void buildMax(){
    for (int i = 0; i < N; i++)
        lookupMax[i][0] = arr[i];
    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 0; (i + (1 << j) - 1) < N; i++) {
            if (lookupMax[i][j - 1] > lookupMax[i + (1 << (j - 1))][j - 1]) lookupMax[i][j] = lookupMax[i][j - 1];
            else lookupMax[i][j] = lookupMax[i + (1 << (j - 1))][j - 1];
        }
    }
}
int queryMax(int L, int R)
{
    int j = (int)log2(R - L + 1);
    if (lookupMax[L][j] <= lookupMax[R - (1 << j) + 1][j])
        return lookupMax[L][j];
 
    else
        return lookupMax[R - (1 << j) + 1][j];
}
int queryMin(int L, int R)
{
    int j = (int)log2(R - L + 1);
    if (lookupMin[L][j] <= lookupMin[R - (1 << j) + 1][j])
        return lookupMin[L][j];
 
    else
        return lookupMin[R - (1 << j) + 1][j];
}
int main(){
    cin >> N >> Q;
    for(int i = 0, u; i < N; i++){
        cin >> u; arr.push_back(u);
    }
    buildMax(); buildMin();
    for(int i = 0, l, r; i < Q;i++){
        cin >> l >> r;
        cout << (queryMax(l,r)-queryMin(l,r))<<endl;
    }
}