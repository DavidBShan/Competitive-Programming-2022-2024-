#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for(int i = 0, N, M; i < T; i++){
        cin >> N >> M; int arr[N][M]; vector<int> org; vector<int> stk; vector<int> notUsed;
        bool flag = false; int curN, curM;
        if(N==1||M==1){cout << "-1" << endl; continue;}
        for(int i = 1; i <= N*M; i++) org.push_back(i);
        for(int i = 1; i <= N*M; i++){
            stk = org; stk.erase(stk.begin()-i-1);
            memset(arr, 0, sizeof arr); 
            arr[0][0] = i; curN = 0; curM = 1; bool finished = false;
            while(!notUsed.empty() && !stk.empty()){
                while(!notUsed.empty()||finished){
                    
                }
                while(!stk.empty()){
                    if(curN-1>=0 && (arr[curN-1][curM]==0 ||arr[curN-1][curM]])
                }
            }
            flag = false; cout << "-1" << endl;
        }
        if(flag){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}