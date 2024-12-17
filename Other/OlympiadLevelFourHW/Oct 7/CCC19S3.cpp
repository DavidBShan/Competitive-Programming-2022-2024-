    #include <bits/stdc++.h>
    using namespace std;
    int a[3][3], got[3][3], cnt = 0, row[3], col[3]; string temp;
    int pos[9][2] = {{1, 1}, {2, 1}, {0, 1}, {1, 2}, {1, 0}, {0, 0}, {2, 0}, {0, 2}};
    int main(){
        ios::sync_with_stdio(0); cin.tie(0); 
        for(int i = 0; i < 3; i++){
            for(int j = 0; j< 3; j++){
                cin >> temp;
                if(temp == "X") {got[i][j] = false; cnt++;  row[i]++; col[j]++;}
                else {got[i][j] = true; a[i][j] = stoi(temp);}
            }
        }
        while(cnt>0){
            bool flag = false;
            for(int i = 0; i < 3 && !flag; i++){
                if(row[i] == 1){
                    if(!got[i][0]) {a[i][0] = 2*a[i][1]-a[i][2]; row[i]--; col[0]--; cnt--; got[i][0] = true;}
                    else if(!got[i][1]) {a[i][1] = (a[i][0]+a[i][2])/2; row[i]--; col[1]--; cnt--; got[i][1] = true;}
                    else if(!got[i][2]) {a[i][2] = 2*a[i][1]-a[i][0]; row[i]--; col[2]--; cnt--; got[i][2] = true;}
                    flag = true;
                }
            }
            for(int i = 0; i < 3 && !flag; i++){
                if(col[i] == 1){
                    if(!got[0][i]){a[0][i] = 2*a[1][i]-a[2][i]; row[0]--; col[i]--; cnt--; got[0][i] = true;}
                    else if(!got[1][i]){a[1][i] = (a[0][i]+a[2][i])/2; row[1]--; col[i]--; cnt--; got[1][i] = true;}
                    else if(!got[2][i]){a[2][i] = 2*a[1][i]-a[0][i]; row[2]--; col[i]--; cnt--; got[2][i] = true;}
                    flag = true;
                }
            }
            for(int i = 0; i < 9; i++){
                int r = pos[i][0], c = pos[i][1];
                if(!got[r][c] && flag==false) {a[r][c] = 0; row[r]--; col[c]--; cnt--; got[r][c] = true; flag = true;}
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j< 3; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }