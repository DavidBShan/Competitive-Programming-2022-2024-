#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0; i < 10;i++){
        map<string,int> smarties; int quotient, reminder, answer=0;
        string colours[] = {"orange","blue","green","yellow","pink","violet","brown"};
        string inp; cin >> inp;
        while(inp!="end"){
            smarties[inp]++;
            cin >> inp;
        }
        for(int i = 0; i < 7;i++){
            quotient = smarties[colours[i]]/7;
            reminder = smarties[colours[i]]%7;
            if(reminder!=0)quotient++;
            answer+=quotient*13;
        }
        answer+=smarties["red"]*16;
        cout << answer<<endl;
    }
}