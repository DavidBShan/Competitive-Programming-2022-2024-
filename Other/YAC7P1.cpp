#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<long long, long long>> odd;
    vector<pair<long long, long long>> even;
    vector<long long> overall;
    long long ans = 0;
    for (long long i = 1, temp; i <= N; i++)
    {
        cin >> temp;
        if (temp % 2 == 0)
            even.push_back({temp, i});
        else
            odd.push_back({temp, i});
    }
    if (!odd.empty())
    {
        ans += (odd.at(0).first / 2);
        overall.push_back(odd.at(0).second);
        odd.erase(odd.begin());
        while(!even.empty()){
            ans+=even.at(0).first/2-1;
            overall.push_back(even.at(0).second);
            even.erase(even.begin());
        }
        while(!odd.empty()){
            ans+=odd.at(0).first/2;
            overall.push_back(odd.at(0).second);
            odd.erase(odd.begin());
        }
    }else{
        while(!even.empty()){
            ans+=even.at(0).first/2;
            overall.push_back(even.at(0).second);
            even.erase(even.begin());
        }
    }
    cout << ans<<endl;
    for(int i = 0; i < overall.size(); i++){
        cout << overall.at(i) << " ";
    }
}