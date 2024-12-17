#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> overall;
    bool hasOdd = false; long long ans = 0;
    long long oddSum = 0; long long evenSum = 0;
    long long firstOdd = 0; long long last;
    vector<int> evenInd, oddInd; int firstInd;
    for (long long i = 1, temp; i <= N; i++){
        cin >> temp;
        if (temp % 2 == 0){
            evenSum+=temp;
            evenInd.push_back(i);
        }
        else {
            if(!hasOdd){
                firstOdd = temp; hasOdd = true; firstInd = i;
            }else{
                last = temp;
                oddSum +=temp;
                oddInd.push_back(i);
            }
        }
    }
    overall.reserve(N);
    if(hasOdd){
        long long lastInd;
        ans += (firstOdd / 2); ans+=evenSum/2-evenInd.size(); 
        if(oddInd.size()%2==0){
            ans+= oddSum/2-oddInd.size()/2;
        }else{
            lastInd = oddInd.back(); oddInd.pop_back();
            oddSum-=last;
            ans+= oddSum/2-oddInd.size()/2;
            ans+=last/2;
            oddInd.push_back(lastInd);
        }
        overall.push_back(firstInd);
        overall.insert(overall.end(), evenInd.begin(), evenInd.end());
        overall.insert(overall.end(), oddInd.begin(), oddInd.end());
    }else{
        ans = evenSum/2;
        overall.insert(overall.end(), evenInd.begin(), evenInd.end());
    }
    cout << ans<<endl;
    for(int i = 0; i < overall.size(); i++) cout << overall.at(i) << " ";
}