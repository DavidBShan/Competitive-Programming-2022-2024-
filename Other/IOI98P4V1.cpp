#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6+5;
int totalParam = 0, N = 0, totalPics = 0;
struct pic {
    int val, xLL, yLL, xUR, yUR;
} pics[MM];

void intersect(pic p1, pic p2, pic* p3) {
    p3->xLL = max(p1.xLL, p2.xLL);
    p3->yLL = max(p1.yLL, p2.yLL);
    p3->xUR = min(p1.xUR, p2.xUR);
    p3->yUR = min(p1.yUR, p2.yUR);
    p3->val = -1 * p1.val * p2.val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a = totalPics; totalPics++;
        cin >> pics[a].xLL >> pics[a].yLL >> pics[a].xUR >> pics[a].yUR;
        pics[a].val = 1; 
        for (int j = 0; j < a; j++) {
            intersect(pics[a], pics[j], &pics[totalPics]); 
            for (j = 0;  j < a; j++)  {
                intersect  (pics[j] , pics[a] , &pics[totalPics]);
                if (pics[totalPics].xUR >= pics[totalPics].xLL && pics[totalPics].yUR >= pics[totalPics].yLL) {
                    if (pics[totalPics].xLL == pics[a].xLL && pics[totalPics].xUR == pics[a].xUR &&
                        pics[totalPics].yLL == pics[a].yLL && pics[totalPics].yUR == pics[a].yUR)  {
                        totalPics = a;
                        break;
                    }  else totalPics++;
                }
            }
        }
    }
    for (int i = 0; i < totalPics; i++) { 
        totalParam += 2 * pics[i].val * (pics[i].xUR - pics[i].xLL + pics[i].yUR - pics[i].yLL);
    }
    cout << totalParam << "\n";
    return 0;
}