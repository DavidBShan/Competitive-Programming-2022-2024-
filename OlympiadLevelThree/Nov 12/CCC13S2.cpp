#include <iostream>
#include <vector>
using namespace std;

int main() {
  int MaxW, NumC;
  cin >> MaxW >> NumC;
  vector<int> WeightL = {0,0,0};
  int GoodC = 0;
  int Random;
  int Total;
  for (int i = 0; i < NumC; i++){
    cin >> Random;
    WeightL.push_back(Random);
  }
  WeightL.push_back(MaxW+1);
  GoodC = 0;
  int i = 3;
  Total = WeightL[i-3] + WeightL[i-2] + WeightL[i-1] + WeightL[i];
  while (Total <= MaxW){
    GoodC = GoodC + 1;
    i = i + 1;
    Total = WeightL[i-3] + WeightL[i-2] + WeightL[i-1] + WeightL[i];
  }
  cout << GoodC;
}