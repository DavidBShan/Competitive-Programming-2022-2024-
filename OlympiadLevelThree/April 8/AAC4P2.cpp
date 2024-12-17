#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q; int lights[N]; int time; bool flag = false;
    for(int i = 0; i < N;i++) cin >> lights[i];
    for(int i = 0; i < Q;i++){
        cin >> time;
        for(int i = 0; i < N;i++){
            if(time%lights[i]!=0){
                cout << lights[i]<< "YEEET"<<endl;
                cout << i+1<<endl; flag = true; break;
            }
        }
        if(!flag) cout << -1 << endl;
        flag = false;
    }
}