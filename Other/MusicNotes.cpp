#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q; pair<int, int> arr[N+1]; memset(arr, 0, sizeof(arr));
    for(int i = 1, temp; i <= N; i++){
        cin >> temp; if(i == 1) arr[i] = {0, temp-1};
        else arr[i] = {arr[i-1].second+1, arr[i-1].second+temp};
    }
    for(int i = 1, temp; i <= Q; i++){
        cin >> temp; 
        int l = 1, r = N, mid;
        while(l <= r){
            mid = (l+r)/2;
            if(arr[mid].first <= temp && temp <= arr[mid].second){
                cout << mid << endl; break;
            }
            else if(arr[mid].second < temp) l = mid+1;
            else r = mid-1;
        }
    }
}