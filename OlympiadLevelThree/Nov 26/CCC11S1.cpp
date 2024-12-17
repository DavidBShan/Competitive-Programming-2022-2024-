#include <iostream>
using namespace std;

int main() {
  int sCount = 0;
  int tCount = 0;
  int NumTime;
  cin >> NumTime;
  string Sentence;
  for (int i = 0; i <= NumTime; i ++){
    getline(cin,Sentence);
    for(signed int j = 0; j < Sentence.length(); j++){
      if (Sentence.at(j) == 'S'||Sentence.at(j)=='s'){
        sCount++;
      }else if (Sentence.at(j) == 'T'||Sentence.at(j)=='t'){
        tCount++;
      }
    }
  }
  if (sCount < tCount){
    cout << "English"<<endl;
  }else{
    cout << "French"<<endl;
  }
}