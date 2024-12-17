#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; string zodiac[] = { "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"}; map<string, pair<int,int>> cows; int age, oAge, oZodiac; vector<string> sentence(8); string curCow, oCow;
    for(int i = 0; i < N;i++){
        for(int i = 0; i < 8;i++) cin >> sentence[i];
        age = distance(zodiac, find(zodiac, zodiac+12, sentence[4]));
        curCow = sentence[0]; oCow = sentence[7];
        oZodiac = cows[oCow].first; oAge = cows[oCow].second;
        if(sentence[3]=="previous"){
            if(age<oZodiac) cows[curCow] = {oZodiac, oAge + oZodiac-age};
            else cows[curCow] = {oZodiac, 12+oAge + oZodiac-age};
        }else{
            if(oZodiac<x)
        }
    }
}