#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> freq; pair<int,int> mostFreq = {0,0}, secondFreq= {0,0}; int N; cin >> N; ;
    for(int i = 0, v; i <N;i++){
        cin >> v; freq[v]++;
    }for(auto const& [val, freqN]: freq){
        if(freqN>=mostFreq.second&&mostFreq.second==secondFreq.second){
            if(mostFreq.first>secondFreq.first&&val<secondFreq.first) secondFreq = {val,freqN};
            else if(mostFreq.first<secondFreq.first&&val>secondFreq.first) secondFreq = {val,freqN};
            else if(mostFreq.first>secondFreq.first&&val>mostFreq.first) mostFreq = {val,freqN};
            else if(mostFreq.first<secondFreq.first&&val<mostFreq.first) mostFreq = {val,freqN};
            else if(freqN>mostFreq.second) secondFreq = {val,freqN};
        }













        else if(freqN>mostFreq.second)mostFreq = {val,freqN};
        else if(freqN>secondFreq.second) secondFreq = {val,freqN};
        else if(freqN==mostFreq.second){
            if(mostFreq.first>secondFreq.first){
                if(mostFreq.first<val){
                    mostFreq = {val,freqN};
                }
            }else{
                if(mostFreq.first>val){
                    mostFreq = {val,freqN};
                }
            }
        }
        else if(freqN==secondFreq.second){
            if(mostFreq.first>secondFreq.first){
                if(secondFreq.first>val){
                    secondFreq = {val,freqN};
                }
            }else{
                if(secondFreq.first<val){
                    secondFreq = {val,freqN};
                }
            }
        }
    }
    cout << abs(mostFreq.first-secondFreq.first)<<endl;
}