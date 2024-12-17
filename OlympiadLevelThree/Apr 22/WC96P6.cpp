#include <bits/stdc++.h>
using namespace std;

long long val(char c){
    if (c >= '0' && c <= '9') return (long long)c - '0';
    else return (long long)c - 'A' + 10;
}

long long toDeci(string str, long long base){
    long long len = str.length(), power = 1, num = 0;
    long long i;
    for (i = len - 1; i >= 0; i--){
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}
 
void convert10tob(long long N, long long b)
{
     if (N == 0)
        return;
     long long x = N % b;
     N /= b;
     if (x < 0)
        N += 1; 
     convert10tob(N, b);
     cout<< (x < 0 ? x + (b * -1) : x);
     return;
}

int main(){
    string num1; long long base1, decimal1; string num2; long long base2, decimal2,decimalSum, desBase; string outputSum;
    for(long long i = 0; i < 5;i++){
        cin >> num1 >> base1;
        decimal1 = toDeci(num1,base1);
        cin >> num2 >> base2;
        decimal2 = toDeci(num2,base2);
        decimalSum = decimal1*decimal2;
        cin >> desBase;
        convert10tob(decimalSum, desBase);
        cout << endl;
    }
}