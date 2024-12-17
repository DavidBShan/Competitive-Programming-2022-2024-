#include <string>
#include <iostream>
#include <sstream>
using namespace std;
#define len 200

int main() {
  char line1[len] = { 0 }, line2[len] = { 0 };
  cin.getline(line1, len);
  cin.getline(line2, len);
  int count[123] = { 0 };
  for(int i=0; i<len; i++) {
    count[(int)line1[i]] ++;
    count[(int)line2[i]] --;
  }

    for(int i=97; i<123; i++) {
        if(count[i] > 0) {
            count[(int)'*'] += count[i];
            if(count[(int)'*'] > 0) {
                cout << "N";
                return 0;
            }
        }
    }

    cout << "A";
    return 0;
}