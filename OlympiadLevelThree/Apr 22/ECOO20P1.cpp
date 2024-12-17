#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string notes[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C"};
    bool flag = false;
    vector<vector<string>> chords;
    for(int i = 0; i < 12;i++){
        chords.push_back({notes[i],notes[i+4],notes[i+7],notes[i+10],notes[i+14],notes[i+17],notes[i+20]});
    }
    cin >> N;
    for(int i = 0; i < N;i++){
        string chordInp[4];
        cin >> chordInp[0]>>chordInp[1]>>chordInp[2]>>chordInp[3];
        for(int j = 0; j < chords.size();j++){
            if(chordInp[0] == chords[j][0]&&chordInp[1]==chords[j][1]&&chordInp[2]==chords[j][2]&&chordInp[3]==chords[j][3]){
                cout << "root"<<endl; flag = true; break;
            }else if(chordInp[0] == chords[j][1]&&chordInp[1]==chords[j][2]&&chordInp[2]==chords[j][3]&&chordInp[3]==chords[j][0]){
                cout << "first"<<endl; flag = true; break;
            }else if(chordInp[0] == chords[j][2]&&chordInp[1]==chords[j][3]&&chordInp[2]==chords[j][0]&&chordInp[3]==chords[j][1]){
                cout << "second"<<endl; flag = true; break;
            }else if(chordInp[0] == chords[j][3]&&chordInp[1]==chords[j][0]&&chordInp[2]==chords[j][1]&&chordInp[3]==chords[j][2]){
                cout << "third"<<endl; flag = true; break;
            }
        }
        if(flag == false) {cout << "invalid"<<endl;}
        flag = false;
    }
}