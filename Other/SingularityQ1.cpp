#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N; long long arr[N+1];
    for(int i = 1; i <= N; i++)  cin >> arr[i];
    int start = 1, end = N, curLen = N; bool flag = false;
    while(!flag){
        if(arr[start]>arr[end]){
            if((curLen/((curLen-1)*arr[end])>=1)) end--;
            else flag = true;
        }else if(arr[start]<=arr[end]){
            if((curLen/((curLen-1)*arr[start])>=1)) start--;
            else flag = true;
        }
    }
    cout << start << " " << end<<endl;
}