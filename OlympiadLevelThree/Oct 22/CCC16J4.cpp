#include <iostream>
#include <string>
using namespace std;

int main() {
  string totalString;
  getline(cin,totalString);
  string stringHr=totalString.substr(0,2);
  string stringMinute = totalString.substr(3,4);
  int hr = stoi(stringHr);
  int minute = stoi(stringMinute);
  int totalTime;
  totalTime = minute+60*hr;
  for (int i = 0; i <120; i++){
    if (totalTime > 420 && totalTime < 600){
      totalTime+=2;
    }
    else if (totalTime> 900 && totalTime < 1140){
      totalTime+=2;
    }else{
      totalTime++;
    }
  }
  totalTime = totalTime%1440;
  minute = totalTime%60;
  hr = (totalTime-minute)/60;
  if (hr<=9){
    stringHr = "0"+to_string(hr);
  }else{
    stringHr = to_string(hr);
  }
  if (minute<=9){
    stringMinute = "0"+to_string(minute);
  }
  else if(minute == 39){
    stringMinute = "40";
  }else{
    stringMinute = to_string(minute);
  }
  cout << stringHr<<":"<<stringMinute;
  return 0;
}