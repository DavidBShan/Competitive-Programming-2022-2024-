#include <iostream>
#include<string.h>
#include <string>
using namespace std;

bool findDuplicate(int num){
  string strNum = to_string(num);
  for(int i=0;i<strNum.size();i++){                    
    for(int j=i+1;j<strNum.size();j++){
      if(strNum[i]==strNum[j]){                  
        return false;
      }
    }
  }
  return true;
}
int main() {
  int intInput;
  cin >> intInput;
  for (int i = intInput+1;i < 10235;i++){
    if (findDuplicate(i) == true){
      cout << i<<endl;
      break;
    }
  }
}