#include <iostream>
using namespace std;

int abso(int num)
{
  if (num < 0)
  {
    num = (-1) * num;
  }
  return num;
}

int main() {
  int Locations[5];
  int Num;
  int PrevNum = 0;
  int NewNum;
  Locations[0] = 0;
  for (int i = 1; i <= 4; i++){
    cin >> NewNum;
    PrevNum += NewNum;
    Locations[i] = PrevNum;
  }
  for (int i = 0; i <= 4; i++){
    for (int j = 0; j <=4; j++){
      Num = abso(Locations[i] - Locations[j]);
      cout << Num << " ";
    }
    cout << endl;
  }
  return 0;
}