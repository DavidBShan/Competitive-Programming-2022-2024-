#include <bits/stdc++.h>
using namespace std;
int M, N; vector<int> ls; vector<int> rs;
bool check(int lmt){
    int i = 0, j = 0, cnt = 0;
    while(i<N&&j<M){
        if(abs(ls[i]-rs[j])<=lmt){
            cnt++; i++; j++;
        }else if(ls[i]<rs[j]){
            i++;
        }else if(ls[i]>rs[j]){
            j++;
        }
    }
    return cnt == min(M,N);
}
int main(){
    cin >> N >> M; int rand, ans;
    for(int i = 0; i < N;i++){
        cin >> rand; ls.push_back(rand);
    }for(int j = 0; j < M;j++){
        cin >> rand; rs.push_back(rand);
    }
    sort(ls.begin(), ls.end()); sort(rs.begin(), rs.end());
    int low = 0, high = 1e9;
    while(low <= high){
        int mid = (low+high)/2;
        if(check(mid)){
            ans = mid; high = mid-1; 
        }else{
            low = mid+1;
        }
    }
    cout << ans;
}