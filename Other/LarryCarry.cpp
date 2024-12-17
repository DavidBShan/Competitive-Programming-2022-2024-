#include <iostream>
#include <vector>
using namespace std;
int N;
vector<long long> nums;
vector<vector<long long>> allCombinations;

bool canAddWithoutCarry(int a, int b) {
    while (a > 0 && b > 0) {
        if ((a % 10 + b % 10) >= 10) return false;
        a /= 10; b /= 10;
    }
    return true;
}

void generateCombinations(vector<long long>& nums, int start, vector<long long>& current, vector<vector<long long>>& allCombinations) {
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        allCombinations.push_back(current);
        generateCombinations(nums, i + 1, current, allCombinations);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0, temp; i < N; i++){cin >> temp; nums.push_back(temp);}
    vector<long long> current;
    generateCombinations(nums, 0, current, allCombinations);
    int max = -1;
    for(int i = 0; i < allCombinations.size(); i++){
        int curLen = allCombinations[i].size();
        int sum = 0;
        for(int j = 0; j < curLen-1; j++){
            sum+=allCombinations[i][j];
            if(canAddWithoutCarry(sum, allCombinations[i][j+1])) continue;
            else curLen = -1;
            if(curLen == -1) break;
        }
        //cout << curLen << '\n';
        if(curLen!=-1 && curLen > max) max = curLen;
    }
    cout << max;
    return 0;
}
