#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
struct node{
    int left, right, Min;
} tree[4*MM]; 

int arr[MM];

void build (int l, int r, int num){
    tree[num].left = l; tree[num].right = r;
    if(l==r) {tree[num].Min = arr[l]; return;}
    int mid = (l+r)/2;
    build(l, mid, num*2); build(mid+1, r, num*2+1);
    tree[num].Min = min(tree[num*2].Min, tree[num*2+1].Min);
}

void update(int pos, int val, int num){
    if (tree[num].left == pos && tree[num].right == pos){
        tree[num].Min = val; return;
    }
    int mid = (tree[num].left + tree[num].right)/2;
    if (pos <= mid) update(pos, val, 2*num);
    else update(pos, val, 2*num+1);
    tree[num].Min = min(tree[2*num].Min, tree[2*num+1].Min);
}

int query(int l, int r, int num){
    if(tree[num].left == l && tree[num].right == r) return tree[num].Min;
    int mid = (tree[num].left + tree[num].right)/2;
    if(r<=mid) return query(l, r, 2*num);
    else if (l > mid) return query(l, r, 2*num+1);
    else return min(query(l, mid, 2*num), query(mid+1, r, 2*num+1));
}

int N, M;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M; vector<int> sol;
    for(int i = 0; i < N; i++) cin >> arr[i];
    build(0, N-1, 1);
    for(int i = 1, a, b; i <= M; i++){
        char temp; cin >> temp >> a >> b;
        if(temp == 'Q'){
            sol.push_back(query(a, b, 1));
        }else{
            update(a, b, 1);
        }
    }
    for(int i: sol) cout << i << "\n";
}