#include <bits/stdc++.h>
using namespace std;

int main(){
    int max; int floor;int rem;
    cin >> max;
    floor=max/4;
    rem=max%4;
    if(rem>floor){
        cout << 0;
    }else{
        cout << ((floor-rem)/5)+1;
    }
}