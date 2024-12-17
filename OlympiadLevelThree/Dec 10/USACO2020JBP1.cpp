    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int N, K; cin >> N >> K; string inpWord; int curLength = 0; 
        for(int i = 0; i < N;i++){
            cin >> inpWord;
            if(i == 0){
                cout << inpWord; curLength = inpWord.size(); continue;
            }
            if(inpWord.size()+curLength<=K){
                cout << " "+inpWord; curLength+=inpWord.size();
            }else{
                cout << endl<<inpWord; curLength = inpWord.size();
            }
        }
        cout << endl;
    }