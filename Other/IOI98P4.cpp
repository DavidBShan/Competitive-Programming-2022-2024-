#include <bits/stdc++.h>
using namespace std;

const int MM = 3e4+5;
struct E { int x, yl, yh, val;};
struct T { int l, r, sum, cnt;};
int n, q;
vector<T> tree(8*MM);

bool cmp(E& a, E& b){ return a.x < b.x || a.x==b.x && a.val > b.val; }

void push_up(int rt){
    if(tree[rt].cnt > 0) tree[rt].sum = arr[tree[rt].r+1] - arr[tree[rt].l];
    else if(tree[rt].l != tree[rt].r) tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    else tree[rt].sum = 0;
}

void rangeUpdate(int rt, int l, int r, int L, int R, int val){
    if(L <= l && r <= R){
        tree[rt].cnt += val;
        push_up(rt);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) rangeUpdate(rt<<1, l, mid, L, R, val);
    if(mid < R) rangeUpdate(rt<<1|1, mid+1, r, L, R, val);
    push_up(rt);
}

int getSum(int rt, int l, int r){
    if(tree[rt].cnt > 0) return arr[r+1] - arr[l];
    if(l == r) return 0;
    int mid = (l + r) >> 1;
    return getSum(rt<<1, l, mid) + getSum(rt<<1|1, mid+1, r);
}

int main() {
    cin >> n;
    for(int i = 0, x1, x2, y1, y2; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        event.push_back({})
    }
}