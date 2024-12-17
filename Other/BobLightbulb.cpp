#include<bits/stdc++.h>
using namespace std;

struct Node {
    int preOn, sufOn, len, preOff, sufOff, mxOn, mxOff;
} seg[200005*4];

void combine (int node, int lchild, int rchild){
    seg[node].len = seg[lchild].len + seg[rchild].len;
    seg[node].preOn = seg[lchild].preOn == seg[lchild].len ? seg[lchild].preOn + seg[rchild].preOn : seg[lchild].preOn;
    seg[node].sufOn = seg[rchild].sufOn == seg[rchild].len ? seg[rchild].sufOn + seg[lchild].sufOn : seg[rchild].sufOn;
    seg[node].preOff = seg[lchild].preOff == seg[lchild].len ? seg[lchild].preOff + seg[rchild].preOff : seg[lchild].preOff;
    seg[node].sufOff = seg[rchild].sufOff == seg[rchild].len ? seg[rchild].sufOff + seg[lchild].sufOff : seg[rchild].sufOff;
    seg[node].mxOn = max({seg[lchild].mxOn, seg[rchild].mxOn, seg[lchild].sufOn + seg[rchild].preOn});
    seg[node].mxOff = max({seg[lchild].mxOff, seg[rchild].mxOff, seg[lchild].sufOff + seg[rchild].preOff});
}

void build(int node, int start, int end) {
    if(start == end) {
        seg[node].len = 1; 
        seg[node].preOff = seg[node].sufOff = seg[node].mxOff = 1;
        seg[node].preOn = seg[node].sufOn = seg[node].mxOn = 0;
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        combine(node, 2*node, 2*node+1);
    }
}

void toggle(int node, int start, int end, int l, int r) {
    if(start > r || end < l) return;
    if(start >= l && end <= r) {
        swap(seg[node].preOn, seg[node].preOff);
        swap(seg[node].sufOn, seg[node].sufOff);
        swap(seg[node].mxOn, seg[node].mxOff);
        return;
    }
    int mid = (start + end) / 2;
    toggle(2*node, start, mid, l, r);
    toggle(2*node+1, mid+1, end, l, r);
    combine(node, 2*node, 2*node+1);
}

int queryOn(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if(start > r || end < l) return 0;
    if(start >= l && end <= r) return seg[node].mxOn;
    int mid = (start + end) / 2;
    return max({seg[2*node].mxOn, seg[2*node+1].mxOn, seg[2*node].sufOn + seg[2*node+1].preOn});
}

int queryOff(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if(start > r || end < l) return 0;
    if(start >= l && end <= r) return (end - start + 1) - seg[node].mxOff;
    int mid = (start + end) / 2;
    return max({seg[2*node].mxOff, seg[2*node+1].mxOff, seg[2*node].sufOff + seg[2*node+1].preOff});
}

int main() {
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    while(q--) {
        string type;
        cin >> type;
        if(type == "TOGGLE") {
            int x; cin >> x;
            toggle(1, 1, n, x, x);
        } else if(type == "ON") {
            int l, r; cin >> l >> r;
            cout << queryOn(1, 1, n, l, r) << "\n";
        } else {
            int l, r; cin >> l >> r;
            cout << queryOff(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}