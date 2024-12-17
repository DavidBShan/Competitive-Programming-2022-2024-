#include <bits/stdc++.h>
using namespace std;
int M,N, temp, maxS = -1,minS = 1, mid,ans; vector<int> seats;
int check(){
    int count = 0, cur = seats[0]; bool flag;
    for(int i = 1; i < seats.size();i++){
        if(cur+mid==seats[i]){flag = true;}
        if(cur+mid<=seats[i]){cur = seats[i];count++;}
    }
    if(count+1 >=M&&flag == true) return 2;
    else if(count+1 >=M) return 1;
    return 0;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N;i++){
        cin >> temp; seats.push_back(temp); 
        maxS = max(maxS,temp);
    }
    maxS-=1;
    sort(seats.begin(),seats.end());
    while(minS <= maxS){
        mid = (minS+maxS)/2;
        if(check()==1 || check()==2){minS = mid+1;} 
        else maxS = mid-1; 
        if(check()==2) ans = mid;
    }
    cout << ans;
}