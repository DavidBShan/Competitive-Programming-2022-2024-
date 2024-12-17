#include <bits/stdc++.h>
using namespace std;
vector<char> shelf;

void swap(int ind1, int ind2){
    char temp = shelf[ind1];
    shelf[ind1] = shelf[ind2];
    shelf[ind2] = temp;
}

int main(){
    string shelfStr; getline(cin, shelfStr);
    int countS = 0; int countM = 0; int countL = 0; int count = 0; bool flag = true;
    for (int i = 0; i<shelfStr.size();i++){
        if(shelfStr.at(i)=='S') countS++; else if(shelfStr.at(i)=='M') countM++; else if(shelfStr.at(i)=='L') countL++; 
        shelf.push_back(shelfStr.at(i));
    }
    for (int i = 0; i < countL;i++){
        if(shelf[i]=='S'){
            for(int j = shelf.size()-1; j >= 0;j--){
                if(shelf[j]=='L'){
                    swap(i,j);
                    count++;
                    break;
                }
            }
        }else if(shelf[i]=='M'){
            for(int j = countL;j < shelf.size();j++){
                if (shelf[j] == 'L')
                {
                    swap(i, j);
                    flag = false;
                    count++;
                    break;
                }
            }
            if(flag = true){
                for(int j = countL-1;j>=0;j--){
                    if (shelf[j] == 'L')
                    {
                        swap(i, j);
                        count++;
                        break;
                    }
                }

            }
            flag = true;
        }
    }
    for(int i = countL;i<countM+countL-1;i++){
        if(shelf[i]=='S'){
            for(int j = shelf.size()-1;j>=0;j--){
                if (shelf[j] == 'M')
                {
                    swap(i, j);
                    count++;
                    break;
                }
            }
        }
    }
    cout << count;
}