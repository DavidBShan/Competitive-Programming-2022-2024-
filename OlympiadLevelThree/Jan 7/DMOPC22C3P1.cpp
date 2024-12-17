#include <bits/stdc++.h>
using namespace std;

int main(){
    long long width, length; cin >> width>>length;
    if(width*length%2==0) cout << width*length/2<<" "<<width*length/2;
    else{
        if(width>length) swap(length,width);//length bigger
        cout << ((length-1)*width/2)+width << " " << ((length-1)*width/2);
    }
}