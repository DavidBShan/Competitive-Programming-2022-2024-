#include<bits/stdc++.h>
using namespace std;

int main(){
    int len; cin >> len; vector<double> flowers; double petals; double average; set<double> temp; double sum = 0; int length; int count = 0;

    for(int i = 0; i < len;i++){
        cin >> petals;
        flowers.push_back(petals);
    }

    for(int i = 0; i < len;i++){
        for(int j = 0; j < len-i;j++){
            length = j;
            while(length>=0){
                sum+=flowers[i+length];
                temp.insert(flowers[i+length]);
                length--;
            }
            average = sum/(j+1);
            auto pos = temp.find(average);

            if (pos != temp.end())
                count++;
            temp.clear();
            sum = 0;
        }
    }
    cout << count;
}