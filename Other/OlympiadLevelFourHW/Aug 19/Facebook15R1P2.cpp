#include <bits/stdc++.h>
using namespace std;
struct node{
    unordered_map<char, node*> ch;
};
node *root;

void clean(node *cur){
    if(cur==nullptr) return;
    for(auto ptr: cur->ch) clean(ptr.second);
    delete cur; cur = nullptr;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        int N; cin >> N;
        long long ans = 0; root = new node();
        for(int j = 0; j < N; j++){
            string str; cin >> str;
            int flag = 0; node *cur = root;
            for(int ch = 0; ch < str.size(); ch++){
                if(!cur->ch.count(str[ch])){
                    cur->ch[str[ch]] = new node();
                    if(!flag) flag=ch+1;
                    cur = cur->ch[str[ch]];
                }else{
                    cur = cur->ch[str[ch]];
                }
            }
            if(!flag) ans+=str.size();
            else ans+=flag;
        }
        cout << "Case #" << i << ": " << ans<<"\n";
        clean(root);
    } 
}