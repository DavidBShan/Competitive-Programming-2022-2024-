#include <iostream>
#include <string>
using namespace std;

int main(){
  int K;
  cin >> K;
  string code;
  cin >> code;
  string Answer= "";
  int S;
  int J;
  string LetterString = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i <code.length(); i++){
    S = 3*(i+1)+K;
    J = LetterString.find(code[i]);
    if ((J-S)<0){
      Answer=Answer+LetterString[J-S+26];
    }else{
      Answer=Answer+LetterString[J-S];
    }
  }
  cout << Answer;
  return 0;
}