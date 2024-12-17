    #include <bits/stdc++.h>
    using namespace std;
    vector<int> allVal; set<int> allPrice; int ans,countF = 0, n, sum = 0; 
    void fun(int i, vector<int>& comb){
        if(i > n) {
            ans = accumulate(comb.begin(),comb.end(),0);
            if(allPrice.find(ans)==allPrice.end()&&ans>=0&&ans<=sum){
                allPrice.insert(ans); countF++;
            }
            return;
        }
        fun(i+1, comb); 
        comb.push_back(allVal[i]); fun(i+1, comb); comb.pop_back();
    }
    int main(){
        cin >> n; vector<int> comb;
        for(int i = 0, temp;i <n;i++){
            cin >> temp; allVal.push_back(temp);
            sum+=temp;
        }
        fun(0,comb);
        cout << countF;
    }