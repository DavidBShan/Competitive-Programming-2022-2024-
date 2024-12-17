#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
typedef vector<int> vi;
typedef array<int, 3> arr;

#define pb push_back
#define f first
#define s second

int __i__, __j__;
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}

#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define Fir(i,a) For(i,0,a)
#define Rof(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define Rif(i,a) Rof(i,0,a)

const int NN = 2e3+2, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int N, a[NN][NN];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    For(r, 1, N+1)
        For(c, 1, N+1){
            if(r % 5 == 3 && N-r != 0 && N-r != 1)a[r][c] = 1;
            if(N % 5 && r == N-2){
                if(c % 5 >= 2 && c % 5 <= 4)a[r][c] = 1;
            }
            if(N % 5 >= 2 && r == N-1)
                if(c % 5 == 3)a[r][c] = 1;
            if(N%5 == 4 && r == N-3)
                if(c % 5 == 3)a[r][c] = 1;
            if(N%5 ==1){
                if(r == N && c == N)a[r][c] = 1;
            }
            else if(N % 5 == 2){
                if(c == N && r >= N-1)a[r][c] = 1;
            }
            else if(N % 5 == 3){
                if(c ==N-1 && r == N-1)a[r][c] =1;
            }
            cout << a[r][c] << " \n"[c == N ];
        }
    return 0;
}