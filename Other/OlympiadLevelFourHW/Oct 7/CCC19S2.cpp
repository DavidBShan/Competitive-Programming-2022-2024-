#include <iostream>
using namespace std;

bool checkPrime(int n){
  if (n <= 1){
    return false;
  }
  if (n <= 3){
    return true;
  }
  if (n % 2 == 0 or n % 3 == 0){
    return false;
  }
  int i = 5;
  while(i * i <= n){
    if (n % i == 0 or n % (i + 2) == 0){
      return false;
    }
    i = i + 6;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++){
    int Y;
    cin >> Y;
    int DY = 2*Y;
    for (int i = 1; i < Y+1; i++){
      if ((checkPrime(i))&&(checkPrime(DY-i))){
        cout << i<<" "<<DY-i<<endl;
        break;
      }
    }
  } 
}