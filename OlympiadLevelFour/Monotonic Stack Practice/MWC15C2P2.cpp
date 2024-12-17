#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> stack; int N; cin >> N;int arr[N], tower[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0, temp; i < N; i++){
        while(!stack.empty() && arr[stack.back()]<=arr[i]) stack.pop_back();
        if(stack.empty()) tower[i] = 0;
        else tower[i] = stack.back();
        stack.push_back(i);
    }
    for(int i = 0; i < N; i++) cout <<i-tower[i]<< " ";
}