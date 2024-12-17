#include <iostream>
using namespace std;

void FlipH(int Array[2][2]){
  int TempNum;
  TempNum = Array[0][0];
  Array[0][0] = Array[1][0];
  Array[1][0] = TempNum;
  TempNum = Array[0][1];
  Array[0][1] = Array[1][1];
  Array[1][1] = TempNum;
}
void FlipV(int Array[2][2]){
  int TempNum;
  TempNum = Array[0][0];
  Array[0][0] = Array[0][1];
  Array[0][1] = TempNum;
  TempNum = Array[1][0];
  Array[1][0] = Array[1][1];
  Array[1][1] = TempNum;
}


int main() {
  string Input;
  int flipperArray[2][2] = {{1,2},{3,4}};
  getline(cin, Input);
  for (int i = 0; i < Input.length();i++){
    if (Input.at(i)=='H'){
      FlipH(flipperArray);
    }else{
      FlipV(flipperArray);
    }
  }
  cout<< flipperArray[0][0];
  cout << " ";
  cout << flipperArray[0][1]<<endl;
  cout << flipperArray[1][0];
  cout << " ";
  cout << flipperArray[1][1]<<endl;
}