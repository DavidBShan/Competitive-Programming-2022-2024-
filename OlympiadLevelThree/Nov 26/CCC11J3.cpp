#include <iostream>
using namespace std;


int main() {
  int Prev;
  int Current;
  cin >> Prev;
  cin >> Current;
  int Temp;
  int count = 0;
  bool flag = true;
  while (flag == true){
    Temp = Current;
    Current = Prev-Current;
    Prev = Temp;
    count++;
    if (Current > Prev){
      flag = false;
    }
  }
  cout << count+2;
}