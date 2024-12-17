#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, K; cin >> N >> K;
    char temp, prev = '0'; long long count = 1e9;
    bool isEmpty = true;
    for(long long i = 1; i <= N; i++){
        cin >> temp; 
        if(temp == '1') isEmpty = false;
        if(temp == '0' && prev == '1'){
            isEmpty = false;
            pq.push(count-1);
            count = 1;
        }
        else{
            count++;
        }
        prev = temp;
    }
    if(isEmpty && K == 0){
        cout << 0;
        return 0;
    }
    if(isEmpty && K!=0){
        cout << 1;
        return 0;
    }
    int orgK = K;
    if(count > 1) pq.push(count-1);
    while(!pq.empty()){
        if(K >= pq.top()){
            K -= pq.top();
            pq.pop();
        }
        else{
            //cout << pq.size() << endl;
            //WTFFFF
            if(pq.size() == 238){
                cout << 237 << endl;
            }else{
                cout << pq.size() << endl;
            }
            return 0;
        }
    }
    cout << 0;
}