#include <bits/stdc++.h>
using namespace std;
int D1 = 1, D2 = 2, D3 = 0, D4 = 0;
map<vector<int>, int> timeMap;
void add(){
    D4++;
    if(D4 == 10){
        D4 = 0; D3++;
    }if(D3 == 6){
        D3 = 0; D2++;
    }if(D2 == 10){
        D1 = 1; D2 = 0;
    }if (D2 == 3 && D1 == 1){
        D2 = 1; D1 = 0;
    } 
}
int main(){
    int N, count = 0, dif;
    cin >> N;
    for(int i = 0; i <= 10000000;i++){
        if(i == (N%720)+1){
            break;
        }
        if(D1 == 0){
            dif = D4-D3;
            if(D3-D2==dif){
                count++; 
            }
        }else{
            dif = D4-D3;
            if(D3-D2==dif&&D2-D1 == dif){
                count++;
            }
        }
        add();
    }
    count+=31*(N/720);
    cout << count;
}