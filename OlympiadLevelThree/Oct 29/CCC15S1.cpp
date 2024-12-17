#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  int num;
  int command;
  cin >> num;
  vector<int> money;
  for (int i = 0; i < num; i ++){
    cin >> command;
    if (command==0){
      money.pop_back();
    }else{
      money.push_back(command);
    }
  }
  cout << accumulate(money.begin(), money.end(), 0);
}