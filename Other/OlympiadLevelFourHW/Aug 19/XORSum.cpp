#include <bits/stdc++.h>
using namespace std;
struct node {
    unordered_map<char, node*> ch;
};
node *root;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    root = new node(); int N; cin >> N;
    for(int i = 0, temp; i < N; i++){
        cin >> temp; node *cur = root;
        for (int i = 17; i >= 0; i--) {
            int bit = ( temp >> i) & 1;
            if (cur->ch[bit] == nullptr) {
                cur->ch[bit] = new node();
            }
            cur = cur->ch[bit];
        }
    }
}