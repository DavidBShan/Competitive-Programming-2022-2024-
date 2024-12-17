#include <bits/stdc++.h>
using namespace std;
int N, ans=0; stack<int> stk;

int main(){
    cin >> N; stk.push(0);
    for(int i = 0, temp; i < N; i++){
        cin >> temp;
        while(stk.top()>temp){
            stk.pop();
        }if(stk.top()!=temp){
            stk.push(temp);ans++;
        }
    }
    cout << ans;
}
