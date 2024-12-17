    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        long N, Alice=0, Duke=0, stones;
        cin >> N;
        for(int i = 0; i < N;i++){
            cin >> stones;
            if(stones%2==0) Duke+=stones/2;
            else Alice+=(stones/2)+1;
        }
        cout << (Alice>=Duke?"Alice":"Duke")<<endl;
    }