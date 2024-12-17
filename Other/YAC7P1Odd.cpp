#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> overall;
    bool hasOdd = false; long long ans;
    long long oddSum = 0;
    vector<int> oddInd; int firstInd; long long lastVal;
    for (long long i = 1, temp; i <= N; i++){
        cin >> temp;
        if(N%2==1 && i==N){
            lastVal = temp;
            oddInd.push_back(i);
            break;
        }
        oddSum+=temp;
        oddInd.push_back(i);
    }
    if(N%2==0){
        ans = oddSum/2-N/2;
    }else{
        ans = oddSum/2-N/2;
        ans+= lastVal/2;
    }
    overall.reserve(N);
    overall.insert(overall.end(), oddInd.begin(), oddInd.end());
    cout << ans<<endl;
    for(int i = 0; i < overall.size(); i++) cout << overall.at(i) << " ";
}