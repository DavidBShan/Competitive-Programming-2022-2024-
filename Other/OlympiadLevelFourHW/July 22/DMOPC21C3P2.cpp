#include <bits/stdc++.h>
using namespace std;

int main(){
    map<long long, long long> mp; long long K; cin >> K;
    if(K==0){
        cout << "1" << endl << "1" << endl;
        return 0;
    }
    for(long long i = 0; i <= 1e6; i++){
        mp[(i*(i+1))/2] = i;
    }
    for(long long i = 1; i <= 1e6; i++){
        long long num = (i*(i+1))/2;
        long long rest = K-num;
        if(!mp.count(rest)){
            continue;
        }
        int m = mp[num]; int n = mp[rest];
        if(n){
            if(m+1+n>1e6) continue;
            else{
                cout << m + 1 + n << endl;
                for(int j = 0; j < m; j++){
                    cout << "0" << " ";
                }
                cout << "1";
                for(int j = 0; j < n; j++){
                    cout << " " << "0";
                }
                cout << endl;
                return 0;
            }
        }else{
            cout << m << endl;
            for(int j=0; j<m; j++) cout << 0 << " \n"[j==m-1];
            return 0;
        }
    }
    cout << "-1" <<endl;
}