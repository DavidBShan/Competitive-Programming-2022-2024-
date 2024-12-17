#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    vector<string> vec;
    string temp;
    for(int i = 0; i < N; i++){
        cin >> temp; vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    for(int i = N-1; i >= 0; i--){
        cout << vec.at(i);
    }
}