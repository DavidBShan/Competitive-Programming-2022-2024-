#include <bits/stdc++.h>
using namespace std;
int P, Y, T; long long testC = 1000000000000000,realTest, ans, minN = 1;
bool check(){
    long long bank = 0; int yearC = 0;
    while(yearC < Y && bank<T){
        bank+=realTest; bank=(long long)(bank*(((double) P+100.0)/100)); yearC++;
    }
    if(yearC>Y){return false;}
    return true;
}
int main(){
    cin >> P >> Y >> T;
    while(testC>=minN){
        realTest = (testC+minN)/2;
        if(check()){ans = realTest; testC = realTest-1;}
        else{minN = realTest+1;}
    }
    cout << (long long) ans;
}