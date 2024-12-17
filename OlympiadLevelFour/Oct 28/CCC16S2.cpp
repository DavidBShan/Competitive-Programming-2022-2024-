#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int choice;
  int amount;
  int country1;
  int country2;
  int totalMin = 0;
  int totalMax = 0;

  vector<int> dmoj;
  vector<int> peg;

  cin >> choice;
  cin >> amount;
  for(int i = 0; i < amount; i++)
  {
    cin >> country1;
    dmoj.push_back(country1);
  
  }
  
  for(int i = 0; i < amount; i++)
  {
    cin >> country2;
    peg.push_back(country2);
  }


  if(choice == 1)
  {
    sort(dmoj.begin(), dmoj.end());
    sort(peg.begin(), peg.end());
    for(int i = 0; i < size(dmoj); i ++)
    {
        totalMin += max(dmoj[i],peg[i]);
    }
    cout << totalMin;
  }

  else if(choice == 2)
  {
    sort(dmoj.begin(), dmoj.end(), greater <>());
    sort(peg.begin(), peg.end());

    for(int i = 0; i < size(dmoj); i ++)
    {
        totalMax += max(dmoj[i],peg[i]);
    }
    cout << totalMax;

  }

}