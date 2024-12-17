#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec; int N, len;
    cin >> N >> len; int arr[N+1];
    for(int i = 1, temp; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++){
        while(!vec.empty() && arr[vec.back()] <= arr[i]) vec.pop_back();
        vec.push_back(i);
        while(!vec.empty() && vec.front()+len <= i) vec.erase(vec.begin());
        if(i>=len) cout << arr[vec.front()] << " ";
    }
}