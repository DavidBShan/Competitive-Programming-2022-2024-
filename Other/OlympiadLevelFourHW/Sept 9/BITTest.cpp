#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3, appleMax = 101;
int N, M, arr[MM];
long long bit[MM], freq[MM];
char op; 
void upd(long long bit[], int end, int val){
    for(int i = end; i < MM; i+=i&-i) bit[i] += val;
}
long long qry(long long bit[], int end){
    long long ans = 0;
    for(int i = end; i; i-=i&-i) ans+=bit[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){ cin >> arr[i]; upd(bit, i, arr[i]); upd(freq, arr[i], 1); }
    for(int i = 1, x, y; i <= M; i++){
        cin >> op >> x;
        if(op=='C'){
            cin >> y;
            upd(bit, x, -arr[x]+y); upd(freq, arr[x], -1); upd(freq, y, 1); arr[x] = y;
        }else if(op=='S'){
            cin >> y;
            cout << qry(bit, y)-qry(bit, x-1) << endl;
        }else{
            cout << qry(freq, x) << endl;
        }
    }
}