#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int num;
  int point;
  cin >> num;
  int SwiftArray[num];
  int SemaphoreArray[num];
  int SwiftSum = 0;
  int SemaphoreSum = 0;
  vector <int>WorkVector;
  for (int i = 0; i<num; i++){
    cin >> point;
    SwiftSum+=point;
    SwiftArray[i] = SwiftSum;
  }
  for(int i = 0; i<num;i++){
    cin>>point;
    SemaphoreSum+=point;
    SemaphoreArray[i] = SemaphoreSum;
  }
  for (int i = 0; i<num;i++){
    if (SemaphoreArray[i]==SwiftArray[i]){
      WorkVector.push_back(i+1);
    }
  }
  if (WorkVector.size()==0){
    cout << "0";
  }else{
     cout <<*max_element(WorkVector.begin(), WorkVector.end())<<endl;
  }
}