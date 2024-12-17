#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int arr[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr+1, arr+N+1);
    int min = 1, max = 1e9;
    while(min < max){
        int mid = (min+max)/2, cnt = 1, last = arr[1];
        for(int i = 2; i <= N; i++){
            if(arr[i]-last >= mid){
                cnt++;
                last = arr[i];
            }
        }
        if(cnt >= M) min = mid+1;
        else max = mid;
    }
    cout << min-1;
}