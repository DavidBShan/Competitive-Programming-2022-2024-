#include <bits/stdc++.h>
using namespace std;
int calculateMinUgliness(int N, vector<int>& leftSizes, vector<int>& rightSizes) {
    vector<int> newLeftSizes(leftSizes.begin(), leftSizes.end());
    vector<int> newRightSizes(rightSizes.begin(), rightSizes.end());
    sort(newLeftSizes.begin(), newLeftSizes.end());
    sort(newRightSizes.begin(), newRightSizes.end());
    int maxStrangeness = 0;
    for (int i = 0; i < N; ++i) {
        int strangeness = abs(newLeftSizes[i] - newRightSizes[i]);
        maxStrangeness = max(maxStrangeness, strangeness);
    }
    return maxStrangeness;
}

int main() {
    int N; cin >> N;
    vector<int> leftSizes; vector<int> rightSizes;
    for (int i = 0, temp; i <= N; ++i){
        cin >> temp;
        leftSizes.push_back(temp);
    }
    for (int i = 0, temp; i < N; ++i){
        cin >> temp;
        rightSizes.push_back(temp);
    }
    for(int i = 0; i <= N; i++){
        int tempTake = leftSizes[0];
        leftSizes.erase(leftSizes.begin());
        //cout << "YO" << leftSizes[0] << endl;
        int minUgliness = calculateMinUgliness(N, leftSizes, rightSizes);
        cout << minUgliness << " ";
        //cout <<"DAMN" << tempTake << endl;
        leftSizes.push_back(tempTake);

    }
    return 0;
}
