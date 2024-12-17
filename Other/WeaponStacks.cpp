#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, ans = 0; cin >> N; int arr[N];
    vector<int> leftStack; vector<int> rightStack;
    for(int i = 0; i < N; i++){
        int x; cin >> x; leftStack.push_back(x); 
    }
    memset(arr, 0, sizeof(arr));
    //cout << leftStack.back() << endl;
    for(int i = 1; i <= N; i++){
        if(arr[i] == 0){
            while(true){
                if(leftStack.back() == i){
                    ans++; leftStack.pop_back(); break; 
                }else{
                    ans++; rightStack.push_back(leftStack.back()); leftStack.pop_back(); arr[rightStack.back()] = 1; 
                }
            }
        }else if(arr[i] == 1){
            while(true){
                if(rightStack.back() == i){
                    ans++; rightStack.pop_back();  break; 
                }else{
                    ans++; leftStack.push_back(rightStack.back()); rightStack.pop_back(); arr[leftStack.back()] = 0; 
                }
            }
        }
    }
    cout << ans;
}