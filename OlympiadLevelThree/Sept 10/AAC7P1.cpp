#include <bits/stdc++.h>
using namespace std;

int main(){
    long long num; long long w; long long h; string ans = "";
    cin >> num;
    for(long long i = 0; i < num;i++){
        cin >> w >> h;
            if (w == 1)
            {
                ans += "bad\n";
            }
            else if (h == 1)
            {
                if (w >= 7)
                {
                    ans += "good\n";
                }
                else
                {
                    ans += "bad\n";
                }
            }
            else if (h >= 4)
            {
                ans += "good\n";
            }
            else if (w >= 4)
            {
                ans += "good\n";
            }
            else
            {
                ans += "bad\n";
            }
    }
    cout << ans;
}