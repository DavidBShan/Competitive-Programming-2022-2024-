#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; string Proc; char Cur; int Count = 0; cin >> N;
    for(int j = 0; j<=N;j++){
        if(j!=0){
            getline(cin, Proc);
            for (int i = 0; i < Proc.size(); i++)
            {
                if (i == 0)
                {
                    Cur = Proc[0];
                    Count++;
                    continue;
                }
                else
                {
                    if (Proc[i] == Cur)
                    {
                        Count++;
                    }
                    else
                    {
                        cout << Count << " " << Cur << " ";
                        Cur = Proc[i + 1];
                        Count = 1;
                    }
                }
            }
            cout << Count << " " << Cur << " " << endl;
            Count = 0;
        }
    }
}