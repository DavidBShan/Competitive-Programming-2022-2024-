#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
struct node{
    int left, right, Min, GCD, cnt;
} tree[3*MM]; 

int arr[MM];

void build (int l, int r, int num){
    tree[num].left = l; tree[num].right = r;
    if(l==r) {tree[num].Min = arr[l]; tree[num].GCD = arr[l]; tree[num].cnt = 1; return;}
    int mid = (l+r)/2;
    build(l, mid, num*2); build(mid+1, r, num*2+1);
    tree[num].Min = min(tree[num*2].Min, tree[num*2+1].Min);
    tree[num].GCD = __gcd(tree[num*2].GCD, tree[num*2+1].GCD);
    tree[num].cnt = 0;
    if(tree[num].GCD == tree[2*num].GCD) tree[num].cnt += tree[2*num].cnt;
    if(tree[num].GCD == tree[2*num+1].GCD) tree[num].cnt += tree[2*num+1].cnt;
}

void update(int pos, int val, int num){
    if (tree[num].left == pos && tree[num].right == pos){
        tree[num].Min = val; tree[num].GCD = val; return;
    }
    int mid = (tree[num].left + tree[num].right)/2;
    if (pos <= mid) update(pos, val, 2*num);
    else update(pos, val, 2*num+1);
    tree[num].GCD = __gcd(tree[2*num].GCD, tree[2*num+1].GCD);
    tree[num].Min = min(tree[2*num].Min, tree[2*num+1].Min);
    tree[num].cnt = 0;
    if(tree[num].GCD == tree[2*num].GCD) tree[num].cnt += tree[2*num].cnt;
    if(tree[num].GCD == tree[2*num+1].GCD) tree[num].cnt += tree[2*num+1].cnt;
}

int queryMin(int l, int r, int num){
    if(tree[num].left == l && tree[num].right == r) return tree[num].Min;
    int mid = (tree[num].left + tree[num].right)/2;
    if(r<=mid) return queryMin(l, r, 2*num);
    else if (l > mid) return queryMin(l, r, 2*num+1);
    else return min(queryMin(l, mid, 2*num), queryMin(mid+1, r, 2*num+1));
}

int queryGCD(int l, int r, int num){
    if(tree[num].left == l && tree[num].right == r) return tree[num].GCD;
    int mid = (tree[num].left + tree[num].right)/2;
    if(r<=mid) return queryGCD(l, r, 2*num);
    else if (l > mid) return queryGCD(l, r, 2*num+1);
    else return __gcd(queryGCD(l, mid, 2*num), queryGCD(mid+1, r, 2*num+1));
}

int queryCNT(int l, int r, int val, int num){
    if(tree[num].left == l && tree[num].right == r) return tree[num].GCD==val? tree[num].cnt : 0;
    int mid = (tree[num].left + tree[num].right)/2;
    if(r<=mid) return queryCNT(l, r, val, 2*num);
    else if (l > mid) return queryCNT(l, r, val, 2*num+1);
    return queryCNT(l, mid, val, 2*num) + queryCNT(mid+1, r, val, 2*num+1);
}

int N, M;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    build(1, N, 1);
    for(int i = 1, a, b; i <= M; i++){
        char temp; cin >> temp >> a >> b;
        if(temp == 'C'){
            update(a, b, 1);
        }else if(temp == 'M'){
            cout << queryMin(a, b, 1) << "\n";
        }else if(temp == 'G'){
            cout << queryGCD(a, b, 1) << "\n";
        }else{
            cout << queryCNT(a, b, queryGCD(a, b, 1), 1) << "\n";
        }
    }
}